/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

//! Made the same left right logical mistake 
//! Here we didn't used return because we don't need to return value of root at that instance instead we need to return original root therfore we only made calls.Another way to do so is by declaring a another void function and then do it and then return original root from main function after making changes.
//* We need to be careful about the situations where we need to use return in recursive functions.


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if (root == NULL)
            return new TreeNode(val);

        else if (root->val > val) 
        {
            if (root->left == NULL)
                root->left = new TreeNode(val);
            else
                insertIntoBST(root->left, val);
        }

        else if (root->val < val) 
        {
            if (root->right == NULL)
                root->right = new TreeNode(val);
            else
                insertIntoBST(root->right, val);
        }

        return root;
    }
};