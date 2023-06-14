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
    vector<int>tree;
    void inorder(TreeNode* root){
        if(root==NULL)
        return; 
        inorder(root->left);
        tree.push_back(root->val);
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int ans=1e9;
        for(int i=1;i<tree.size();i++){
            ans=min(ans,tree[i]-tree[i-1]);
        }
        return ans;
    }
};