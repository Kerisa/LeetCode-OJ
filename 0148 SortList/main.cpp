/*
 * By	: Alisa
 * Date	: 15-08-02
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 *
 * πÈ≤¢≈≈–Ú
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
    ListNode * Merge(ListNode *L1, ListNode *L2)
    {
        ListNode *p = L1, *q = L2, *ret, *r;
        if (!L2) return L1;
        if (!L1) return L2;
        if (p->val < q->val)
        {
            ret = r = p;
            p = p->next;
        }
        else
        {
            ret = r = q;
            q = q->next;
        }
        while(p && q)
        {
            if (p->val < q->val)
            {
                r->next = p;
                p = p->next;
            }
            else
            {
                r->next = q;
                q = q->next;
            }
            r = r->next;
        }
        if (p) r->next = p;
        if (q) r->next = q;
        return ret;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *t = slow->next;
        slow->next = 0;
        
        ListNode *LL1 = sortList(head);
        ListNode *LL2 = sortList(t);
        
        return Merge(LL1, LL2);
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

	for (int i=0; i<21; ++i, s=s->next)
		s->next = new ListNode(rand()%3000);

	out(&p);
	out(S.sortList(&p));
	return 0;
}