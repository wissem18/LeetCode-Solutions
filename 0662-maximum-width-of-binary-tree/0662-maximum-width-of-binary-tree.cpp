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
long long MOD=1e10;
   vector<vector<long long>>l;
 void dfs(TreeNode* root,long long ind,int level){
   if(!root)
       return ;
      l[level].push_back(ind);
   dfs(root->left,(2*ind)%MOD,level+1);
   dfs(root->right,(2*ind+1)%MOD,level+1);

 }
int widthOfBinaryTree(TreeNode* root) {
l.resize(3000);
dfs(root,0,0);
long long ans=0;
    for (int i = 0; i < l.size(); ++i) {
        if(l[i].empty())
            break;
        ans=max(ans,l[i][l[i].size()-1]-l[i][0]+1);
    }
    return ans;
}
};