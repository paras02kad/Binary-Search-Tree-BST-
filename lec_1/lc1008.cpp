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
//! given any Array just converting it in InOrder means just to sort the given array.
//! Because InOrder of BST is always sorted.
//! It is still incorrect and need to be completed.
//! Failed test case is [8,5,1,7,10,12] it gives [7,1,10,null,5,8,12].

class Solution
{
public:
    TreeNode *machine(vector<int> &nums, int i, int j)
    {
        if (i > j)
            return NULL;
        int mid = i + (j - i) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = machine(nums, i, mid - 1);
        root->right = machine(nums, mid + 1, j);
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        vector<int> InOrd =
            sort(preorder.begin(), preorder.end());
        TreeNode *ans = machine(InOrd, 0, InOrd.size() - 1);
        return ans;
    }
};

//! Approach - 2
//! We made use of LC-701 for declaring a temproary node and then putting it in the right place in our BST.
//* This is a better Approach then approach - 1.

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *temp = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++)
        {
            insertIntoBST(temp, preorder[i]);
        }
        return temp;
    }
};