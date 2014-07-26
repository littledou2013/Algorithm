/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int result;
    bool hasPathSum(TreeNode *root, int sum) {
       if (root == NULL)
            return false;
       if (root->left == NULL && root->right == NULL && sum == root->val)
            return true;
        sum -= root->val;
        if (hasPathSum(root->left,sum))
            return true;
        if (hasPathSum(root->right,sum))
             return true;
        sum +=root->val;
       return false;
    }
};
