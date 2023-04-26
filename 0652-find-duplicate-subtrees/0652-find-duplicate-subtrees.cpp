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
int preorder(TreeNode* root,vector<TreeNode*>&res,map<int,int>&cnt,map<string,int>&id){
if(root==NULL)
return 0;
string s=to_string(preorder(root->left,res,cnt,id))+"/"+to_string(root->val)+"/"+to_string(preorder(root->right,res,cnt,id));
if(!id.count(s)){
id[s]=id.size()+1;
}
cnt[id[s]]++;
if(cnt[id[s]]==2)
res.push_back(root);
return id[s];
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<int,int>cnt;
        map<string,int>id;
        vector<TreeNode*>res;
        int x=preorder(root,res,cnt,id);
        return res;
    }
};