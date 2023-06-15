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
    vector<int>levels;
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    void dfs(TreeNode* root,int level){
        if(!root)
            return ;
        dfs(root->left,level+1);
        levels[level]+=root->val;
        dfs(root->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        int n=maxDepth(root);
        levels.resize(n);
        dfs(root,0);
        int mx=INT_MIN;
        int ans=0;
        for(int i=0;i<n;i++){
            if(levels[i]>mx){
                mx=levels[i];
                ans=i;
            }
        }
        return ans+1;
    }
};