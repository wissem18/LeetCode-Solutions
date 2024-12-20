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
    void dfs(TreeNode* leftChild, TreeNode* rightChild, int level) {
        if (leftChild == NULL || rightChild == NULL) {
            return;
        }
        
        if (level % 2 == 0) {
            int temp = leftChild->val;
            leftChild->val = rightChild->val;
            rightChild->val = temp;
        }

        dfs(leftChild->left, rightChild->right, level + 1);
        dfs(leftChild->right, rightChild->left, level + 1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left,root->right,0);
        return root;
    }
};