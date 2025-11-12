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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }
        TreeNode *root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, int preSt, int preEd, vector<int> &inorder, int inSt, int inEd, map<int, int> &inMap)
    {
        if (preSt > preEd || inSt > inEd)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preSt]);
        int inRoot = inMap[root->val];
        int numLeft = inRoot - inSt;
        root->left = buildTree(preorder, preSt + 1, preSt + numLeft, inorder, inSt, inRoot - 1, inMap);
        root->right = buildTree(preorder, preSt + numLeft + 1, preEd, inorder, inRoot + 1, inEd, inMap);
        return root;
    }
};