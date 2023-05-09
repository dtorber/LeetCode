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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return esSimetric(root -> left, root -> right);
    }
    
    bool esSimetric (TreeNode* r1, TreeNode* r2) {
        unsigned short int nuls = 0;
        if (r1 == nullptr) nuls++;
        if (r2 == nullptr) nuls++;
        if (nuls > 0) return nuls == 2;
        return r1 -> val == r2 -> val && esSimetric (r1 -> left, r2 -> right) && esSimetric (r1 -> right, r2 -> left);
    }
};