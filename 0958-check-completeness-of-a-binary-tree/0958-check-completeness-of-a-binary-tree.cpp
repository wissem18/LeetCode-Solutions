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
int nbNodes(TreeNode* root){
    if(root==NULL)
    return 0;
    return 1+nbNodes(root->left)+nbNodes(root->right);
}
bool dfs(TreeNode* root,int curindex,int n){
    if(root==NULL)
    return true;
    if(curindex>=n)
    return false;
    return dfs(root->left,curindex*2+1,n)&&dfs(root->right,curindex*2+2,n);
}
    bool isCompleteTree(TreeNode* root) {
        return dfs(root,0,nbNodes(root));
          
    }
};