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
    int maxDepth(TreeNode* root){
        if(!root)
            return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    int ans=0;
    void dfs(TreeNode* root,int level){
        if(!level&&root){
            ans=root->val;
            return;
        }
        if(!root)
            return;
        dfs(root->right,level-1);
        dfs(root->left,level-1);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        int mx=maxDepth(root);
        dfs(root,mx-1);
        return ans;
    }
};