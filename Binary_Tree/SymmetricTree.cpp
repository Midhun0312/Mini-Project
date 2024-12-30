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

class Solution
{
    bool check(TreeNode *leftnode, TreeNode *rightnode)
    {
        if (!leftnode && !rightnode)
            return true;
        if (!leftnode || !rightnode)
            return false;
        return (leftnode->val == rightnode->val) && check(leftnode->left, rightnode->right) && check(leftnode->right, rightnode->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return check(root->left, root->right);
    }
};