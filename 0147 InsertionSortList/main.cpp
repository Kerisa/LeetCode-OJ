/*
 * By	: Alisa
 * Date	: 15-08-03
 *
 * Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0x7fffffff), *ins = &dummy, *p = &dummy;
        dummy.next = head;
        if (!head) return 0;
        
        for (p=head; p && p->next;)
        {
			for (ins = ins->val<p->next->val ? ins : &dummy; ins != p; ins=ins->next)
					if (ins->next->val > p->next->val)
					{
						ListNode *t  = ins->next;
						ListNode *t1 = p->next->next;
						ins->next = p->next;
						p->next->next = t;
                    
						p->next = t1;
						
						goto NEXT;
					}
			p = p->next;
NEXT:		p = p;
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
	
	srand(time(0));
	
	ListNode p(rand()%520), *s = &p;
	
	for (int j=1; j<32; ++j, s=s->next)
			s->next = new ListNode(rand()%520);
	out(&p);
	cout << endl << endl;
	
	out(S.insertionSortList(&p));
	
	cout << endl;

	return 0;
}