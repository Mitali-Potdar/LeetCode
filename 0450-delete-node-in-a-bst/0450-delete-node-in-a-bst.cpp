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
    int findminfromright(TreeNode* root){
        while(root->left != nullptr)
            root = root->left;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root; 
        else if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);       
        else{
            if(root->left == NULL && root->right == NULL){
                delete(root);
                return NULL;
            }else if(root->right == NULL){
                auto temp = root->left;
                delete(root); 
                return temp;
            }else if(root->left == NULL){
                auto temp = root->right;
                delete(root); 
                return temp;
            }else{
                root->val = findminfromright(root->right);
                root->right = deleteNode(root->right, root->val);
            }	
        }
        return root;    
    }
};