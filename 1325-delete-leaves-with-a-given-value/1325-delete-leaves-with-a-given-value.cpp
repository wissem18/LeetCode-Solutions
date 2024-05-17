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
    void delNode(TreeNode* root, int target){
        if(!root)
            return ;
        delNode(root->left,target);
        delNode(root->right,target);
        if(root->left){
         if(!root->left->left&&!root->left->right&&root->left->val==target)
             root->left=NULL;
        }
        if(root->right){
            if(!root->right->left&&!root->right->right&&root->right->val==target)
             root->right=NULL;
        
        }   
            
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
       delNode(root,target);
        if(!root->left&&!root->right&&root->val==target)
            return NULL;
       return root;
    }
};