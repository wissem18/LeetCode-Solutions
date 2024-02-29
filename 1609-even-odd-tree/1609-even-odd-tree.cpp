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
    vector<vector<int>> levels;

    void bfs(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> cur;
            while (sz--) {
                TreeNode *c = q.front();
                q.pop();
                cur.push_back(c->val);
                if (c->left != NULL)
                    q.push(c->left);
                if (c->right != NULL)
                    q.push(c->right);
            }
            levels.push_back(cur);
        }
    }

    bool isEvenOddTree(TreeNode *root) {
        bfs(root);
    
        for (int i = 0; i < levels.size(); ++i) {
            if(i%2==0){
               int lst=0;
                for (int j = 0; j < levels[i].size(); ++j) {

                    if(levels[i][j]<=lst||levels[i][j]%2==0)
                        return false;
                    lst=levels[i][j];
                }
            }
            else{
                int lst=1e9;
                for (int j = 0; j < levels[i].size(); ++j) {
                    if(levels[i][j]>=lst||levels[i][j]%2)
                        return false;
                    lst=levels[i][j];
                }
            }
        }
        return true;
    }
};