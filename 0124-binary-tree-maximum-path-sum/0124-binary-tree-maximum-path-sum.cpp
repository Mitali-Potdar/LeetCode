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
    int res = INT_MIN;
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        int r = solve(root-> right);
        int l = solve(root->left);
        int temp = max(l,r) + root->val;
        if(max(l, r) < 0) temp = root->val;
        res = max(max(temp, l + r + root->val), res);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return res;
    }
};