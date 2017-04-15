/*
 * By	: Alisa
 * Date	: 15-08-02
 *
 * Á´±íµÄÑ­»·ÓÒÒÆ
 */

#include <iostream>
#include <ctime>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p = head, *list_end = head;
        int i, count = 0;

        if (!head) return head;
        
		while (list_end->next) {++count; list_end = list_end->next;}
		++count;
        k %= count;
        if (!k) return head;
        
        for (p = head,i=1; p && i<count-k; p=p->next, ++i);
        
        ListNode *t = p;
        t->next = 0;
        p = p->next;
        
        list_end->next = head;
        
        return p;
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

	for (int j=1; j<16; ++j, s=s->next)
			s->next = new ListNode(j);
	out(&p);
	cout << endl << endl;
	for (int i=0; i<20; ++i)
	{
		s = &p;
		for (int j=1; j<16; ++j, s=s->next)
			s->next = new ListNode(j);
		cout << i << "\t:\n";
		out(S.rotateRight(&p, i));
		cout << endl;
	}
	return 0;
}