
class Solution {
/* * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     * };
 */
public:
    void dfs(TreeNode* root,int level,vector<long long> &levels){
    if(root==NULL)
        return;
    levels[level]+=root->val;
    dfs(root->left,level+1,levels);
    dfs(root->right,level+1,levels);
}
long long kthLargestLevelSum(TreeNode* root, int k) {
vector<long long> levels(1e5+1);
dfs(root,0,levels);
sort(levels.rbegin(),levels.rend());
if(levels[k-1])
    return levels[k-1];
return -1;
}
};