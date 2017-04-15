/*
 * By	: Alisa
 * Date	: 15-08-12
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note: You may assume that duplicates do not exist in the tree.
 */
 
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* BuildChild(vector<int>& in, int front_in, int end_in, vector<int>& pre, int front_pre, int end_pre)
    {
        TreeNode * ret = new TreeNode(pre[front_pre]);
        if (front_in == end_in)
            return ret;
        
        int i;
        for (i=front_in; i<=end_in; ++i)
		{
            if (in[i] == ret->val) break;
		}
        
		if (i > front_in)
			ret->left = BuildChild(in, front_in, i-1, pre, front_pre+1, end_pre-i+front_in+1);
		if (i < end_in)
			ret->right = BuildChild(in, i+1, end_in, pre, front_pre+i-front_in+1, end_pre);
        return ret;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode * ret = 0;
        
        if (!preorder.size() || !inorder.size())
			return ret;
        
        ret = new TreeNode(preorder[0]);
        
        int i;
        for (i=0; i<inorder.size(); ++i)
		{
            if (inorder[i] == ret->val) break;
		}
        
		if (i > 0 && i != inorder.size())
			ret->left = BuildChild(inorder, 0, i-1, preorder, 1, i);
		if (i < preorder.size()-1)
			ret->right = BuildChild(inorder, i+1, preorder.size()-1, preorder, i+1, preorder.size()-1);
        return ret;
    }
};

int main()
{
	Solution S;
	int i [] = {8,4,9,2,10,5,1,6,13,3,14,7,15};
	int p [] = {1,2,4,8,9,5,10,3,6,13,7,14,15};
	S.buildTree(vector<int>(p,p+1), vector<int>(i,i+1));
	return 0;
}