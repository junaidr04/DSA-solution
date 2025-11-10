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
public:
    int diameter = 0;
    int height(TreeNode *root)
    {
        int ans;
        if (root == NULL)
            return 0;
        int l = height(root->left);
        int r = height(root->right);
        diameter = max(diameter, l + r);
        ans = 1 + max(l, r);
        return ans;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        height(root);
        return diameter;
    }
};