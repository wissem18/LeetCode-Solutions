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
    map<pair<int,int>,vector<TreeNode*>>mem;
    vector<TreeNode*>allBST(int s,int e){
        vector<TreeNode*>res;
        if(s>e){
            res.push_back(nullptr);
            return res;
        }
        if(mem.count({s,e}))
            return mem[{s,e}];
        for(int i=s;i<=e;i++){
            vector<TreeNode*>left=allBST(s,i-1);
            vector<TreeNode*>right=allBST(i+1,e);
            for(auto x:left){
                for(auto y:right){
                    TreeNode* root=new TreeNode(i,x,y);
                    res.push_back(root);
                                       
                }
            }
        }
        return mem[{s,e}]=res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return allBST(1,n);
    }
};