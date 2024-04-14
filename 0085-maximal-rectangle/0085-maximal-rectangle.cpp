class Solution {
public:
 
int maximalRectangle(vector<vector<char>> &matrix) {
    const int n = matrix.size();
    const int m = matrix[0].size();
    vector<int>left(m,0),right(m,m),height(m,0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int curl = 0, curr = m;
        for (int j = 0; j < m; j++) { // compute height
            if (matrix[i][j] == '1') height[j]++;
            else height[j] = 0;
        }
        for (int j = 0; j < m; j++) { // compute left
            if (matrix[i][j] == '1') left[j] = max(left[j], curl);
            else {
                left[j] = 0;
                curl = j + 1;
            }
        }
        // compute right (from right to left)
        for (int j = m - 1; j >= 0; j--) {
            if (matrix[i][j] == '1') right[j] = min(right[j], curr);
            else {
                right[j] = m;
                curr = j;
            }
        }
        // compute the area of rectangle
        for (int j = 0; j < m; j++)
            ans = max(ans, (right[j] - left[j]) * height[j]);
    }
    return ans;
}

};