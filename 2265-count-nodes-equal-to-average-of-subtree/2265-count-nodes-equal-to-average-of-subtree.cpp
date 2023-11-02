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
 int ans=0;
pair<int,int> dfs(TreeNode* root){
    if(!root)
        return{0,0};
    pair<int,int> l=dfs(root->left);
    pair<int,int> r=dfs(root->right);
    int sum=l.first+r.first+root->val;
    int cnt=l.second+r.second+1;
    if(sum/cnt==root->val)
        ans++;
    return {sum,cnt};
}
int averageOfSubtree(TreeNode* root) {
dfs(root);
return ans;
}
};