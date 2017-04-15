/*
 * By	: Alisa
 * Date	: 15-08-03
 *
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
		ListNode ret(-1), *ins = &ret;
        ListNode dummy(-1), *p = &dummy;
        ListNode *next_p, *next_i;
        dummy.next = head;
		        
		if (!head || !head->next) return head;
        
        while (p && p->next)
        {
            if (p->next->val < x)
            {
                next_p = p->next->next;
                ins->next = p->next;
                p->next->next = 0;
                p->next = next_p;

                ins = ins->next;
            }
            else p = p->next;
        }
		ins->next = dummy.next;
        return ret.next;
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
	srand(time(0));
	Solution S;
	ListNode p(rand()%50), *s = &p;
	
	for (int j=1; j<16; ++j, s=s->next)
			s->next = new ListNode(rand()%50);
	out(&p);
	cout << endl << endl;
	
	int x;
	cin >> x;
	
	out(S.partition(&p, x));
	cout << endl;

	return 0;
}