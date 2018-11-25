
/*
    Given a complete binary tree, count the number of nodes.

    Note:
        In a complete binary tree every level, except possibly the last, is completely filled,
        and all nodes in the last level are as far left as possible.
        It can have between 1 and 2h nodes inclusive at the last level h.

    Example:
    Input:
         1
       /   \
      2     3
     / \   /
    4   5 6

    Output: 6
*/

// 递归计算完全二叉树

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *lhs, TreeNode *rhs) : val(x), left(lhs), right(rhs) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        int left = countLeft(root);
        int right = countRight(root);
        if (left == right)
            return (1 << (left)) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int countLeft(TreeNode* root) {
        int depth = 0;
        while (root)
            ++depth, root = root->left;
        return depth;
    }

    int countRight(TreeNode* root) {
        int depth = 0;
        while (root)
            ++depth, root = root->right;
        return depth;
    }
};

#include <cassert>

int main()
{    
    assert(Solution().countNodes(new TreeNode(0, new TreeNode(1, new TreeNode(3), new TreeNode(4)), new TreeNode(2))) == 5);
    assert(Solution().countNodes(nullptr) == 0);
    assert(Solution().countNodes(new TreeNode(0)) == 1);
    assert(Solution().countNodes(new TreeNode(0, new TreeNode(1), new TreeNode(2))) == 3);
    assert(Solution().countNodes(new TreeNode(0, new TreeNode(1), nullptr)) == 2);
    assert(Solution().countNodes(new TreeNode(0, new TreeNode(1, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(5), new TreeNode(6)))) == 7);
    return 0;
}