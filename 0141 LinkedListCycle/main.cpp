/*
 * By	: Alisa
 * Date	: 15-08-03
 *
 * Given a linked list, determine if it has a cycle in it.
 * ͬ142
 */

#include <iostream>
#include <ctime>
using namespace std;
//Definition for singly-linked list.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x=0) : val(x), next(NULL) {}
	ListNode(int x, ListNode *p) : val(x), next(p) {}
};

class Solution {
public:
    bool detectCycle(ListNode *head) {
        if (!head) return false;
        
        ListNode *fast = head, *slow = head;
		if (fast->next && fast->next->next)
		{
			do{
				fast = fast->next->next;
				slow = slow->next;
			}while (fast != slow && fast->next && fast->next->next);
			
			if (fast == slow)
				return true;
		}
		return false;
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
	ListNode p[10];
	p[0].val = 1; p[0].next = &p[1];
	p[1].val = 2; p[1].next = &p[2];
	p[2].val = 3; p[2].next = &p[3];
	p[3].val = 4; p[3].next = &p[4];
	p[4].val = 5; p[4].next = &p[5];
	p[5].val = 6; p[5].next = &p[6];
	p[6].val = 7; p[6].next = &p[4];
		
	cout << ((ListNode*)S.detectCycle(&p[0]))->val << endl;

	return 0;
}