/*
    Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

    Note:
    You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

    Example 1:
    Input: root = [3,1,4,null,2], k = 1
      3
     / \
    1   4
     \
      2
    Output: 1

    Example 2:
    Input: root = [5,3,6,2,4,null,null,1], k = 3
          5
         / \
        3   6
       / \
      2   4
     /
    1
    Output: 3

    Follow up:
    What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/

// 计算二叉搜索树中第 k 小的值

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *lhs, TreeNode *rhs) : val(x), left(lhs), right(rhs) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            return 0;

        return InorderTraversal(root, &k);
    }

    int InorderTraversal(TreeNode* root, int* remain)
    {
        int num = -1;
        if (root->left)
            num = InorderTraversal(root->left, remain);

        if (!*remain)
            return num;

        --(*remain);
        if (*remain == 0)
            return root->val;

        if (root->right)
            num = InorderTraversal(root->right, remain);
        return num;
    }
};

#include <cassert>

int main()
{
    for (int i = 1; i <= 5; ++i)
        assert(Solution().kthSmallest(new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(5)), i) == i);
    assert(Solution().kthSmallest(nullptr, 1) == 0);
    assert(Solution().kthSmallest(new TreeNode(0), 1) == 0);
    assert(Solution().kthSmallest(new TreeNode(4, new TreeNode(3), new TreeNode(6)), 2) == 4);
    assert(Solution().kthSmallest(new TreeNode(4, nullptr, new TreeNode(6, nullptr, new TreeNode(9, nullptr, new TreeNode(16)))), 4) == 16);
    return 0;
}