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
void inorder(TreeNode* root,vector<int>&ans){
     if(!root)
         return ;
   inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
 }
    int getMinimumDifference(TreeNode* root) {
      vector<int>a;
        inorder(root,a);
        int ans=1e9;
        for(int i=1;i<a.size();i++){
            ans=min(ans,a[i]-a[i-1]);
        }
        return ans;
    }
};