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
    int helper(TreeNode* root,bool isLeft){
        if(!root)
            return 0;
        if(!root->left&&!root->right){
            if(isLeft)
                return root->val;
            else
                return 0;
        }
        int ans=helper(root->left,true)+helper(root->right,false);
        return ans;
    }
    int sumOfLeftLeaves(TreeNode* root) {
      return helper(root,false);        
    }
};