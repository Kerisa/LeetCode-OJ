/*
 * By	: Alisa
 * Date	: 15-08-12
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode* BuildChild(vector<int>& in, int front_in, int end_in, vector<int>& post, int front_post, int end_post)
    {
        TreeNode * ret = new TreeNode(post[end_post]);
        if (front_in == end_in)
            return ret;
        
        int i;
        for (i=front_in; i<=end_in; ++i)
		{
            if (in[i] == ret->val) break;
		}
        
		if (i > front_in)
			ret->left = BuildChild(in, front_in, i-1, post, front_post, end_post+i-front_in-1);
		if (i < end_in)
			ret->right = BuildChild(in, i+1, end_in, post, front_post+i-front_in, end_post-1);
        return ret;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode * ret = 0;
        
        if (!postorder.size() || !inorder.size())
			return ret;
        
        ret = new TreeNode(postorder[postorder.size()-1]);
        
        int i;
        for (i=0; i<inorder.size(); ++i)
		{
            if (inorder[i] == ret->val) break;
		}
        
		if (i > 0)
			ret->left = BuildChild(inorder, 0, i-1, postorder, 0, i-1);
		if (i < postorder.size()-1)
			ret->right = BuildChild(inorder, i+1, postorder.size()-1, postorder, i, postorder.size()-2);
        return ret;
    }
};

int main()
{
	Solution S;
	int i [] = {8,4,9,2,10,5,1,6,13,3,14,7,15};
	int p [] = {8,9,4,10,5,2,13,6,14,15,7,3,1};
	S.buildTree(vector<int>(i,i), vector<int>(p,p));
	return 0;
}