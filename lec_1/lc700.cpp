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
//! Made a silly mistake of not putting return before calling a recursive function.
//! Another silly mistake was gave wrong direction of searing according the val and root's value.
//! We made use of property of BST about the position of values with respect to the root of BST.


/*
* Asymptotic analysis
* Best Case = O(log(n)) --> it is because of balanced binary tree it works similar to binary search. --> Because most of the time half of values to be searched are eliminated with help of BST property.
* Worst Case = O(n) --> Where n is the number of nodes (In case of skewed binary search tree)
* Average Case = O(n)

! SC = same as TC in best and worst case.

*/
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        //* Base Case
        if (root == NULL)
            return NULL;
            //! case - 1
        else if (root->val == val)
            return root;
              //! case - 2 
        else if (val > root->val)
            return searchBST(root->right, val);
            //! case - 3 
        else if (val < root->val)
            return searchBST(root->left, val);

            //! If we get nothing in the tree then finally return NULL.

        return NULL;
    }
};