/*
 * By	: Alisa
 * Date	: 15-07-22
 * 
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their 
 * nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
 
#include <iostream>
#include <time.h>

using namespace std;

//  Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry;
		ListNode *ret;
		ListNode *p1 = l1, *p2 = l2, *p3;

		p3 = ret = new ListNode((p1->val + p2->val)%10);
		carry = (p1->val + p2->val) / 10;
		p1 = p1->next;
		p2 = p2->next;

		while (p1 && p2)
		{
			int tmp = p1->val + p2->val + carry;
			p3->next = new ListNode(tmp%10);
			carry = tmp / 10;
			p1 = p1->next;
			p2 = p2->next;
			p3 = p3->next;
		}
		
		while (p1)
		{
			p3 ->next = new ListNode((p1->val + carry)%10);
			carry = (p1->val + carry) / 10;
			p3 = p3->next;
			p1 = p1->next;
		}
		
		while (p2)
		{
			p3 ->next = new ListNode((p2->val + carry)%10);
			carry = (p2->val + carry) / 10;
			p3 = p3->next;
			p2 = p2->next;
		}

		if (carry)
		{
			p3 ->next = new ListNode(carry%10);
			carry = carry / 10;
			p3 = p3->next;
		}
		return ret;
    }
};

// test
#define N 8
int main()
{
	Solution S;
	srand(time(0));
	
	
do{
	ListNode *l1 = new ListNode(5), *l2 = new ListNode(5), *ret;
	ListNode *p1 = l1, *p2 = l2, *p3;

	int lim1 = rand() % N;
	for (int i=0; i<lim1; ++i, p1=p1->next)
		p1->next = new ListNode(9);

	int lim2 = rand() % N;
	for (int i=0; i<lim2; ++i, p2=p2->next)
		p2->next = new ListNode(rand()%10);

	ret = S.addTwoNumbers(l1, l2);
	
	p1 = l1; 	p2 = l2;	p3 = ret;

	cout << "L1: ";
	while(p1) { cout << p1->val; p1 = p1->next; }
	cout << "\nL2: ";
	
	while(p2) { cout << p2->val; p2 = p2->next; }
	cout << "\nret: ";
	
	while(p3) { cout << p3->val; p3 = p3->next;	}
	cout << endl;

	// release l1, l2, ret
	p1 = l1;
	p2 = l2;
	p3 = ret;
	while(p1)
	{
		ListNode *d = p1;
		p1 = p1->next;
		delete d;
	}
	while(p2)
	{
		ListNode *d = p2;
		p2 = p2->next;
		delete d;
	}
	while(p3)
	{
		ListNode *d = p3;
		p3 = p3->next;
		delete d;
	}

	int dummy;
	cin >> dummy;
}while(cin);
	
	return 0;
}