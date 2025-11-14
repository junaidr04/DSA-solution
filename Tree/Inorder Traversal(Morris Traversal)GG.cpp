/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        vector<int> ans;
        Node *cur = root;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                ans.push_back(cur->data);
                cur = cur->right;
            }
            else
            {
                Node *pre = cur->left;
                while (pre->right != NULL && pre->right != cur)
                {
                    pre = pre->right;
                }
                if (pre->right == NULL)
                {
                    pre->right = cur;
                    cur = cur->left;
                }
                else
                {
                    pre->right = NULL;
                    ans.push_back(cur->data);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};