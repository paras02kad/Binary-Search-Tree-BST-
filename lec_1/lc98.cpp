//*We need to keep in check that all the nodes to the left of root has to have a smaller value.And same goes for right of root.
//* We need to keep in mind the test case where we have a single node as test case.
//! We have used 'long long' with functions which goes much deeper than INT_MIN and INT_MAX and we have also used typecasting in long long near max and min function.
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
//! Approach - 1 --> slightly Amateur way of validating a BST.(Almost a Brute Force way)
//! TC = O(n*n)
class Solution
{
public:
    long long machine_g(TreeNode *root)
    {
        if (root == NULL)
            return LLONG_MIN; //* INT_MIN for long long ie LLONG_MIN;
        //! Type casting root->val to long long.
        return max((long long)(root->val), max(machine_g(root->right), machine_g(root->left)));
    }
    long long machine_m(TreeNode *root)
    {
        if (root == NULL)
            return LLONG_MAX; //* INT_MAX for long long ie LLONG_MAX;
                              //! Type casting root->val to long long.
        return min((long long)(root->val), min(machine_m(root->right), machine_m(root->left)));
    }

    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;
        //! Important checkmark for checking nodes that are only a single node with no left and right nodes.
        if (root->right == NULL && root->left == NULL)
            return true;
        if (root->val > machine_g(root->left) && root->val < machine_m(root->right))
            if (isValidBST(root->right) && isValidBST(root->left))
                return true;
        return false;
    }
};

//! Approach - 2 --> Hint: InOrder Traversal;
//* We will make use of property of Binary Tree that InOrder traversal of BST always Sorted.
//! TC = O(n); Because we are visiting every node in the given BST.
//! SC = O(n) where n is the number of nodes present.We made a vector to store all of them.

class Solution
{
public:
    void Inorder(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        Inorder(root->left, v);
        v.push_back(root->val);
        Inorder(root->right, v);
        return;
    }

    bool isValidBST(TreeNode *root)
    {
        vector<int> v;

        Inorder(root, v);

        //! Make sure instead of it!=v.end() we use it!=v.end()-1 to avoid accessing unnecessary condition.

        for (auto it = v.begin(); it != v.end() - 1; it++)
            //! We Haven't made use of (*it) <= *(it + 1) as it fails in [2,2,2] test case.
            if ((*it) < *(it + 1))
                continue;
            else
                return false;
        return true;
    }
};

//* More optimized approach of approach - 2 (Here we made us of some global variables).(We can do it without declaring global variables too by passing them as parameter in our inOrder function)
//! We have removed the vector part And also got a good gain over TC and SC simultaneously
//! TC = O(n) where n is number of nodes in worst case we might have to check for all the nodes.
//! SC = O(1) Because we have removed vector for checking for storing nod values.

class Solution
{
public:
    TreeNode *prev = NULL;
    bool flag = true;
    void Inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        Inorder(root->left);
        if (prev != NULL && prev->val >= root->val)
        {
            flag = false;
            return;
        }
        prev = root;
        Inorder(root->right);
        return;
    }

    bool isValidBST(TreeNode *root)
    {

        Inorder(root);
        return flag;
    }
};