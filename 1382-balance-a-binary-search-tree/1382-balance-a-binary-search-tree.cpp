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
    vector<int> a;

    TreeNode *helper(int l, int r) {
        if(l>r)
            return nullptr;
        int mid=(l+r)/2;
        TreeNode* left=helper(l,mid-1);
        TreeNode* right=helper(mid+1,r);
        return new TreeNode(a[mid],left,right);
    }

    void inorder(TreeNode *root) {
        if (!root)
            return;
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }

    TreeNode *balanceBST(TreeNode *root) {
        inorder(root);
        int n=a.size();
        return helper(0,n-1);
    }
};