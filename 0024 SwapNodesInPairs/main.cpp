/*
 * By	: Alisa
 * Date	: 15-08-02
 *
 * ²Î¿¼Ìâ25
 */

#include <iostream>

using namespace std;

//Definition for singly-linked list.
 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
	inline bool FindNextTwo(ListNode *p, ListNode **n1, ListNode **n2)
	{
		if (!p->next) return false;
		*n1 = p;
		*n2 = p->next;
		return true;
	}

	inline void Reverse(ListNode *n1, ListNode *n2)
	{
		if (!n2) return;

		n2->next = n1;
	}
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = head, *first;
        ListNode *n1, *n2, *end_now, *next_p;
        bool bfind;

		if (!head || !head->next) return head;

        first = p->next;
		end_now = head;
		p = first->next;
		first->next = end_now;
		end_now->next = p;
        
		while (p && p->next)
		{
			next_p = p->next->next;
			if (!(bfind = FindNextTwo(p, &n1, &n2))) break;
			Reverse(n1, n2);
			end_now->next = n2;
			end_now = p;
			p = next_p;
		}
		end_now->next = p;
		return first;
    }
};

void Out(ListNode* head)
{
	ListNode *p = head;
	while (p)
	{
		cout << p->val << ' ';
		p = p->next;
	}
	cout << endl;
}

int main()
{
	Solution S;
	for (int i=0; i<14; ++i)
	{
		ListNode *q = new ListNode(0), *p = q;
		for (int j=1; j<11; ++j)
		{
			p->next = new ListNode(j);
			p = p->next;
		}
		cout << i << "\t: ";
		Out(S.swapPairs(q));
	}
	return 0;
}