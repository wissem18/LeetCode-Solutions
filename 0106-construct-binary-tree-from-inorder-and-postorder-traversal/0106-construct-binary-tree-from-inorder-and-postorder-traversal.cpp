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
    TreeNode* build(vector<int>& inorder,int i,int j ,vector<int>& postorder,int a,int b){
        if(i>j||a>b)
        return NULL;
        TreeNode* root=new TreeNode(postorder[b]);
        int s=i;
        while(root->val!=inorder[s])s++;
        root->left=build(inorder,i,s-1,postorder,a,a+s-i-1);
        root->right=build(inorder,s+1,j,postorder,a+s-i,b-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
     return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);   
    }
};