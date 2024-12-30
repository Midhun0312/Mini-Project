// Populate each next pointer to point to its next right node.If there is no next right node, the next pointer should be set to NULL.
// Initially,
//     all next pointers are set to NULL.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int t = q.size();
            Node *prev = q.front();
            q.pop();
            if (prev->left)
                q.push(prev->left);
            if (prev->right)
                q.push(prev->right);
            for (int i = 1; i < t; ++i)
            {
                prev->next = q.front();
                prev = q.front();
                q.pop();
                if (prev->left)
                    q.push(prev->left);
                if (prev->right)
                    q.push(prev->right);
            }
            prev->next = nullptr;
        }
        return root;
    }
};