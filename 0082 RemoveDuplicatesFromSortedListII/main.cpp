/*
 * By	: Alisa
 * Date	: 15-08-03
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 */

#include <iostream>
#include <ctime>
using namespace std;
//Definition for singly-linked list.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1), *beg = &dummy, *p;
		dummy.next = head;

        if (!head) return 0;

        for (;beg && beg->next && beg->next->next;)
        {
            if (beg->next->val == beg->next->next->val)
            {
                p = beg->next->next->next;
                while(p && p->val == beg->next->val) p = p->next;
				beg->next = p;
            }
			else beg=beg->next;
        }
		return dummy.next;
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
	ListNode p(0), *s = &p;
	
	srand(time(0));

	for (int j=1; j<43; ++j, s=s->next)
			s->next = new ListNode(rand()%2);
	out(&p);
	cout << endl << endl;
	
	out(S.deleteDuplicates(&p));
	cout << endl;

	return 0;
}