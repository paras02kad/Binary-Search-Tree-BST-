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

//! We will have some sort of similar approach as Binary Search.And then a recursive Function to do multiple times.

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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *ans = machine(nums, 0, nums.size() - 1);
        return ans;
    }
};

