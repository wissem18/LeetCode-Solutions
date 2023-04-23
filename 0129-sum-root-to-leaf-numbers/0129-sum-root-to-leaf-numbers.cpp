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
int rec(TreeNode* root,int cursum){
     if(root==NULL)
         return 0 ;
    cursum=cursum*10+root->val;
   if(root->left==NULL&&root->right==NULL)
       return cursum;
   return rec(root->left,cursum)+rec(root->right,cursum);
 }
 int sumNumbers(TreeNode* root) {
  return rec(root,0);
}
};