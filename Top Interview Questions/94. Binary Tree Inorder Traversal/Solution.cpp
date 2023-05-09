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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res(0);
        if (root != nullptr) inOrder(root, res);
        return res;
    }
    
    void inOrder (TreeNode* root, vector<int>& res) {
        if (root -> left != nullptr) inOrder(root -> left, res);
        res.push_back(root -> val);
        if (root -> right != nullptr) inOrder(root -> right, res);
    }
};