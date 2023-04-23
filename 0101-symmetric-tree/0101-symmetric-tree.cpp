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

bool isSymmetric(TreeNode* root) {
if(root==NULL)
    return true;
queue<TreeNode*>q;
q.push(root->left);
q.push(root->right);
while(!q.empty()){
    TreeNode* l=q.front();
    q.pop();
    TreeNode* r=q.front();
    q.pop();
    if(r==NULL||l==NULL){
       if (l!=r)
       return false;
    }
    else{if(r->val!=l->val)
    return false;
    q.push(l->left);
    q.push(r->right);
    q.push(l->right);
    q.push(r->left);
}
}
return true;
}
};