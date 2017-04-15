/*
 * By	: Alisa
 * Date	: 15-07-25
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 */

#include <iostream>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
	bool FindNextK(ListNode *p, int k, ListNode **pk1, ListNode **pk2)
	{
		int i = k-1;

		*pk1 = p;
		for (;i && p; --i, p = p->next);
		*pk2 = p;

		if (!i && p) return true;
		else return false;
	}
	bool Reverse(ListNode *n1, ListNode *n2)
	{
		if (!n2) return false;	// 不足k的不翻转

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *n1, *n2, *k1, *k2, *first;
		bool bFind;

		if (!FindNextK(head, k, &n1, &n2)) return head;
		first = n2;
		
		ListNode *final1, *final2;
		do{
			bFind = FindNextK(n2->next, k, &k1, &k2);
			if (!bFind) // 连接最后不翻转的部分
			{
				final1 = n1;
				final2 = k1;
			}
			Reverse(n1, n2);
			n1->next = k2;
			n1 = k1;
			n2 = k2;
		} while (bFind);
		final1->next = final2;
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
		for (int j=1; j<10; ++j)
		{
			p->next = new ListNode(j);
			p = p->next;
		}
		cout << i << "\t: ";
		Out(S.reverseKGroup(q, i));
	}
	return 0;
}