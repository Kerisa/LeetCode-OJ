/*
 * By	: Alisa
 * Date	: 15-08-02
 *
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * eg:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 *
 * 也可以优化一下，找到m后直接遍历翻转到n，最后连接两端
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
    bool Reverse(ListNode *n1, ListNode *n2)
	{
		if (!n2) return false;

		ListNode *t1 = n1, *t2 = n1, *end = n2;
		while (n1 != end)
		{
			t1 = n1;
			n1 = n1->next;
			t1->next = t2;
			t2 = t1;
		}
		n2 ->next = t2;
		return true;
	}
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int c = 0;
        ListNode dummy(0), *p = head, *b1 = 0, *b2 = 0, *b1_pre = 0, *b2_fol = 0;
		if (m == n) return head;
		if (m == 1) {b1 = head; b1_pre = &dummy;}
		for (int c=1; p; ++c, p=p->next)
        {
            if (c == m-1)
			{
				b1 = p->next;
				b1_pre = p;
			}
            if (c == n)
            {
                b2 = p;
				b2_fol = b2->next;
                break;
            }
        }
            
        if (!b1 || !b2) return head;
        
        Reverse(b1, b2);
		b1_pre->next = b2;
		b1->next = b2_fol;
        return m==1 ? b2 : head;
                
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
	ListNode p(1), *s = &p;

	for (int j=2; j<17; ++j, s=s->next)
			s->next = new ListNode(j);
	out(&p);
	cout << endl << endl;

	out(S.reverseBetween(&p, 1, 16));
	cout << endl;
	
	return 0;
}