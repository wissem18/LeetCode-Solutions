vector<int>ans;
void bfs(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        int mx=INT_MIN;
        while(sz--){
            TreeNode* cur=q.front();
            q.pop();
            mx=max(mx,cur->val);
            if(cur->left!=NULL)
                q.push(cur->left);
            if(cur->right!=NULL)
                q.push(cur->right);
        }
        ans.push_back(mx);
    }
}
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)
            return {};
        ans.clear();
        bfs(root);
        return ans;
    }
};
