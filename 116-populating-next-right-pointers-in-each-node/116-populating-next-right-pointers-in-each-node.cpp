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
    void joinLefttoRight(Node *Left, Node *Right)
    {
        if (Left == NULL)
            return;

        Left->next = Right;
        joinLefttoRight(Left->left, Left->right);
        joinLefttoRight(Left->right, Right->left);
        joinLefttoRight(Right->left, Right->right);
    }

    Node *connect(Node *root)
    {
        if (!root)
            return root;

        joinLefttoRight(root->left, root->right);
        return root;
    }
};