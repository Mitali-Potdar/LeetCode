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
 int d = 0;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int L = minDepth(root->left);
        int R = minDepth(root->right);
        if(min(L, R) == 0) return 1 + max(L, R);
        else return 1 + min(L, R);
    }
};