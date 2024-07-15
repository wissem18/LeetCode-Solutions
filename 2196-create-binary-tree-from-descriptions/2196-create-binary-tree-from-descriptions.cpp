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
map<int,pair<int,int>>m;
    void buildTree(TreeNode* root){
        if(!root)
            return ;
        
        if(m[root->val].first!=0)
            root->left=new TreeNode(m[root->val].first);

        if(m[root->val].second!=0)
            root->right=new TreeNode(m[root->val].second);
        buildTree(root->left);
        buildTree(root->right);

    }
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
        //find the root
        unordered_set<int> nodes;
        for (auto x: descriptions) {
            nodes.insert(x[0]);
            if (x[2] == 1) {
                m[x[0]].first = x[1];
            } else {
                m[x[0]].second = x[1];
            }
        }
        for (auto x: descriptions)
            nodes.erase(x[1]);
        int root = *nodes.begin();
        TreeNode *ans = new TreeNode(root);
        buildTree(ans);
        return ans;
    }
};