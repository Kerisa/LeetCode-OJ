/*
 * By	: Alisa
 * Date	: 15-08-03
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 *
 * 用翻转+合并优化为O(1)空间
 */

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
//Definition for singly-linked list.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
class Solution {
public:
	void reorderList(ListNode* head) {
		ListNode *fast = head, *slow = head;
		vector<ListNode*> s;
		if (!head) return;
		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow = !fast->next ? slow : slow->next;
		for (slow=slow->next; slow; s.push_back(slow), slow=slow->next);
		fast->next = 0;

		int cur = s.size() - 1;
		ListNode *t, *t1;
		fast = head;
		while(fast && cur>=0)
		{
			t = s[cur--];
			t1 = fast->next;
			fast->next = t;
			t->next = t1;
			fast = t1;
		}
		return;
	}
};
*/

class Solution{
public:
	void reorderList(ListNode *head) {
        ListNode *slow = head, *ps = slow;
        ListNode *fast = head;
		if (!head)return;
        while(fast && fast->next){
			ps = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast){
			ps = slow;
            slow = slow->next;
            fast->next = 0;
        }
        fast = head;
        head = fast;
		ps->next = 0;
        slow = reverseList(slow);
        while(slow){
            ListNode *nextSlow = slow->next;
            slow->next = fast->next;
            fast->next = slow;
            fast = slow->next;
            slow = nextSlow;
        }
    }

ListNode * reverseList(ListNode *head){
        ListNode *newHead = 0;
        while (head){
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
};

void out(ListNode *p)
{
	while(p)
	{
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	Solution S;
	srand(time(0));
	ListNode p(0), *s = &p;

	for (int j=1; j<14; ++j, s=s->next)
			s->next = new ListNode(j);
	out(&p);
	cout << endl << endl;
	
S.reorderList(0);
		out(0);
		S.reorderList(&p);
		out(&p);
		
		cout << endl;

	return 0;
}