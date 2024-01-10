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
    vector<vector<int>>adj;
    void build(TreeNode* root){
      if(!root)
          return ;
      int cur=root->val;
      if(root->left){
          adj[cur].push_back(root->left->val);
          adj[root->left->val].push_back(cur);
          build(root->left);
      }
      if(root->right){
          adj[cur].push_back(root->right->val);
          adj[root->right->val].push_back(cur);
          build(root->right);
      }
    }
    int ans=0;
    void dfs(int s,int p=-1,int mx=0){
        ans=max(ans,mx);
        for(auto c:adj[s]){
            if(c==p)continue;
            dfs(c,s,mx+1);
        }
    }
    int amountOfTime(TreeNode *root, int start) {
    adj.resize(1e5+1);
    build(root);
    dfs(start);
      
    return ans;
    }
};