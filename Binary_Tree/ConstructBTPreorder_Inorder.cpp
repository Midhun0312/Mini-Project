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
    TreeNode *f(vector<int> &preorder, int pre_s, int pre_e, vector<int> &inorder, int in_s, int in_e, unordered_map<int, int> &mp)
    {
        if (pre_s > pre_e || in_s > in_e)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_s]);
        int pt = mp[preorder[pre_s]];
        int left = pt - in_s;
        int right = in_e - pt;
        root->left = f(preorder, pre_s + 1, pre_s + left, inorder, in_s, pt - 1, mp);
        root->right = f(preorder, pre_s + left + 1, pre_e, inorder, pt + 1, in_e, mp);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mp;
        int n = preorder.size();
        for (int i = 0; i < n; ++i)
            mp[inorder[i]] = i;
        TreeNode *root = f(preorder, 0, n - 1, inorder, 0, n - 1, mp);
        return root;
    }
};