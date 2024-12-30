// Implement the BSTIterator class that represents an iterator over the in - order traversal of a binary search tree(BST) :


public:
    BSTIterator(TreeNode *root)
    {
        node = root;
        if (node)
            st.push(node);
        while (node->left)
        {
            node = node->left;
            st.push(node);
        }
    }

    int next()
    {
        TreeNode *t = st.top();
        st.pop();
        int v = t->val;
        t = t->right;
        while (t)
        {
            st.push(t);
            t = t->left;
        }
        return v;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};