class Solution {
public:
int largestSubmatrix(vector<vector<int>>& matrix) {
    int n=matrix.size(),m=matrix[0].size();
vector<vector<int>>endHere(m,vector<int>(n,0));
    for (int i = 0; i < m; ++i) {
        endHere[i][0]=matrix[0][i];
        for (int j = 1; j < n; ++j) {
          if(matrix[j][i])
              endHere[i][j]=endHere[i][j-1]+1;
        }
    }
 int ans=0;
    for (int i = 0; i < n; ++i) {
        vector<int>cur;
        for (int j = 0; j < m; ++j) {
          cur.push_back(endHere[j][i]);
        }
        sort(cur.rbegin(),cur.rend());
        for (int j = 0; j < m; ++j) {
            ans=max(ans,cur[j]*(j+1));
        }
    }
    return ans;
}
};