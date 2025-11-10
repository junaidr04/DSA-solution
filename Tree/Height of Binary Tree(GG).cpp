/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    int height(Node *root)
    {
        int ans;
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 0;
        int l = height(root->left);
        int r = height(root->right);
        ans = 1 + max(l, r);
        return ans;
    }
};