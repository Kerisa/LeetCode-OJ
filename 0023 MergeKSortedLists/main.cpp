/*
 * By	: Alisa
 * Date	: 15-07-25
 *
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity.
 */

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
	ListNode* MergeIn(ListNode *L1, ListNode *L2)
	{
		ListNode *New = 0, *ret = 0;
		if (L1 && L2)
		{
			if (L1->val > L2->val)
			{
				ret = New = L2;
				L2 = L2->next;
			}
			else
			{
				ret = New = L1;
				L1 = L1->next;
			}
		}

		while (L1 && L2)
		{
			if (L1->val > L2->val)
			{
				New->next = L2;
				L2 = L2->next;
			}
			else
			{
				New->next = L1;
				L1 = L1->next;
			}
			New = New->next;
		}
		if (!New)
		{
		    if (L1) ret = L1;
		    else if (L2) ret = L2;
		}
		else
		{
		    if (L1) New->next = L1;
		    else if (L2) New->next = L2;
		}

		return ret;
	}

	ListNode* division(vector<ListNode*>& lists, int f, int r)
	{
		if (r == f) return lists[f];

		int div = (r + f) / 2;

		ListNode *p = division(lists, f, div);
		ListNode *q = division(lists, div+1, r);

		return MergeIn(p, q);
	}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (!lists.size()) return 0;
		return division(lists, 0, lists.size()-1);
    }
};

void Out(ListNode* head, unsigned int s)
{
	ListNode *p = head;
	while (p)
	{
		cout << p->val << '\t';
		p = p->next;
	}
	cout << endl;
}

int main()
{
	Solution S;
	vector<ListNode*> in;
	for (int i=0; i<400000; ++i)
	{
		in.push_back(new ListNode(0));
		ListNode *p = in[i];
		for (int j=i; j<100000; j+=2*i+3, p=p->next)
			p->next = new ListNode(j);
	}
//	for (int i=0; i<10; ++i)
//		Out(in[i]);
	cout<<"\n----------------------------\n";
	Out(S.mergeKLists(in), 0);
	return 0;
}


