/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        //* Base case
        if(root==NULL)return NULL;
        //* case - 1
        if(p->val == root->val)return p;
        //* case - 2
        if(q->val == root->val)return q;
        //* case - 3
        if (root->val > p->val && root->val < q->val || root->val < p->val && root->val > q->val)
            return root;
        //* case - 4
        else if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        //* case - 5
        else if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
            //* If nothing happens 
            return NULL;
    }
};