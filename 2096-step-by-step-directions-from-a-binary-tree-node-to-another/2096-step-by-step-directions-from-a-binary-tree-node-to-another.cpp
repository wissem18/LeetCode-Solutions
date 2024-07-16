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
bool findPath(TreeNode *node, int val, string &path) {
    if (node == nullptr) return false;

    if (node->val == val) return true;

    // Try left subtree
    path.push_back('L');
    if (findPath(node->left, val, path)) {
        return true;
    }
    path.pop_back();  // Remove last character

    // Try right subtree
    path.push_back('R');
    if (findPath(node->right, val, path)) {
        return true;
    }
    path.pop_back();  // Remove last character

    return false;
}

string getDirections(TreeNode *root, int startValue, int destValue) {
    string rootTostart = "", rootTodest = "";
    findPath(root, startValue, rootTostart);
    findPath(root, destValue, rootTodest);
    int j = 0;
    while (j < rootTostart.size() && rootTostart[j] == rootTodest[j])
        j++;

    string ans = "";
    for (int i = j; i < rootTostart.size(); ++i) {
        ans += 'U';
    }
    for (int i = j; i < rootTodest.size(); ++i) {
        ans += rootTodest[i];
    }
    return ans;
}
};