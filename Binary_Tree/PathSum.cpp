class Solution
{
    bool f(TreeNode *root, int k, int c)
    {
        if (!root)
            return false;
        c += root->val;
        if (!root->left && !root->right)
        {
            return k == c;
        }
        return f(root->left, k, c) || f(root->right, k, c);
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        return f(root, targetSum, 0);
    }
};


//simple

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return root->val == targetSum;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};