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
    void helper(TreeNode* root,int cur,int &depth,int &val){
        if(!root)
            return;
        if(cur==depth-1){
            TreeNode* l=new TreeNode(val);
            TreeNode* r=new TreeNode(val);
            TreeNode* left_subtree=root->left;
            TreeNode* right_subtree=root->right;
            root->left=l;
            root->right=r;
            l->left=left_subtree;
            r->right=right_subtree;
            return;
        }
        helper(root->left,cur+1,depth,val);
        helper(root->right,cur+1,depth,val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
     if(depth==1){
         TreeNode* nroot=new TreeNode(val);
         nroot->left=root;
         return nroot;
     }
        else{
            helper(root,1,depth,val);
            return root;
        }
    }
};