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
    string ans="";
    void helper(TreeNode* root, string cur){
        if(!root)
            return ;
        cur=char(root->val+'a')+cur;
        if(!root->left&&!root->right){
            if(ans==""||ans>cur)
                ans=cur;
        }
        helper(root->left,cur);
        helper(root->right,cur);
    }
    string smallestFromLeaf(TreeNode* root) {
        helper(root,"");
        return ans;
    }
};