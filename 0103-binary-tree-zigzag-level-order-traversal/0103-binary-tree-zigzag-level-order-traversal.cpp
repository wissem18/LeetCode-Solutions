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
int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n=maxDepth(root);
vector<vector<int>>res(n);
if(root==NULL)
    return res;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        pair<TreeNode*,int>cur=q.front();
        q.pop();
        res[cur.second].push_back(cur.first->val);

            if (cur.first->left != NULL)
                q.push({cur.first->left,cur.second+1});

            if (cur.first->right != NULL)
                q.push({cur.first->right,cur.second+1});
    }
    for(int i=0;i<res.size();i++){
        if(i%2)
        reverse(res[i].begin(),res[i].end());
    }
    return res;
}
};