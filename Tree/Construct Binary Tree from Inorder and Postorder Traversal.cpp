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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }
        TreeNode *root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, int inSt, int inEd,
                        vector<int> &postorder, int postSt, int postEd,
                        map<int, int> &inMap)
    {
        if (inSt > inEd || postSt > postEd)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[postEd]);
        int inRoot = inMap[root->val];
        int numRight = inEd - inRoot;
        root->right = buildTree(inorder, inRoot + 1, inEd, postorder, postEd - numRight, postEd - 1, inMap);
        root->left = buildTree(inorder, inSt, inRoot - 1, postorder, postSt, postEd - numRight - 1, inMap);
        return root;
    }
};