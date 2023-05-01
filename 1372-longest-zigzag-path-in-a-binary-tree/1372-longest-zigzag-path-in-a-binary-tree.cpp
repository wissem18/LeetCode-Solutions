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
int count(TreeNode* root,int dir,int cnt){
if(!root)
    return 0;
ans=max(ans,cnt);
    if(dir==0){
      count(root->left,1,cnt+1);
      count(root->right,0,1);
    }
    else{
        count(root->right,0,cnt+1);
        count(root->left,1,1);
    }
    return ans;
}
    int longestZigZag(TreeNode* root) {
        return max(count(root,0,0),count(root,1,0));
    }
};