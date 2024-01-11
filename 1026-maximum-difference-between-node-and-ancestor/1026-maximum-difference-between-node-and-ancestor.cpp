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
int mxDiff(TreeNode* root,int mx=0,int mn=1e6 ){
    if(!root)
        return mx-mn;
    return max(mxDiff(root->left,max(mx,root->val),min(mn,root->val)),mxDiff(root->right,max(mx,root->val),min(mn,root->val)));
}
int maxAncestorDiff(TreeNode* root) {
return mxDiff(root);
}
};