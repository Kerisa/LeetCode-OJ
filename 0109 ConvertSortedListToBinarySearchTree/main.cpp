/*
 * By	: Alisa
 * Date	: 15-08-03
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x=-1) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *fast = head, *slow = head, *ps = 0;
        if (!head) return 0;
        while(fast->next && fast->next->next)
        {
			fast = fast->next->next;
			ps = slow;
			slow = slow->next;
		}
		TreeNode *ret = new TreeNode(slow->val);
		if (ps) ps->next = 0;
		ret->left = slow != head ? sortedListToBST(head) : 0;
		ret->right = slow->next ? sortedListToBST(slow->next) : 0;
		
		return ret;		
    }
};

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
	p[6].val = 7; p[6].next = 0;

	TreeNode *T = S.sortedListToBST(0);

	return 0;
}