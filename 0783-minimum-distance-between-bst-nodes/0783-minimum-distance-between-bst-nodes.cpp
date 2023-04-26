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
    void preorder(TreeNode* root){
        if(root==NULL)
        return; 
        preorder(root->left);
        tree.push_back(root->val);
        preorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        preorder(root);
        sort(tree.begin(),tree.end());
        int ans=1e9;
        for(int i=1;i<tree.size();i++){
            ans=min(ans,tree[i]-tree[i-1]);
        }
        return ans;
    }
};