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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;        
        queue <TreeNode*> q; 
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();            
            swap(node->left, node->right);
            for(auto& e: {node->left, node->right}) 
                if(e) q.push(e);                    
        }
        return root;
        // if(root==NULL)
        //     return NULL;
        // invertTree(root->left); //Call the left substree
        // invertTree(root->right); //Call the right substree
        // // Swap the nodes
        // TreeNode* temp = root->left;
        // root->left = root->right;
        // root->right = temp;
        // return root;
    }
};