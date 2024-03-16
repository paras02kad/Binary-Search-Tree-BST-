/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//! Approach - 1 --> We use InOrder Traversal  in reverse order to calculate sum.

class Solution
{
public:
    void machine(TreeNode*root, int& sum)
    {
        if (root == NULL)
            return;

        machine(root->right, sum);

        sum += root->val;
        root->val = sum;
        machine(root->left, sum);
    }

    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        machine(root, sum);
        return root;
    }
};