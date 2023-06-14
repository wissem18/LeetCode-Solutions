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
void preorder(TreeNode* root,vector<int>&ans){
     if(!root)
         return ;
    ans.push_back(root->val);
    preorder(root->left,ans);
    preorder(root->right,ans);
 }
    int getMinimumDifference(TreeNode* root) {
      vector<int>a;
        preorder(root,a);
        sort(a.begin(),a.end());
        int ans=1e9;
        for(int i=1;i<a.size();i++){
            ans=min(ans,a[i]-a[i-1]);
        }
        return ans;
    }
};