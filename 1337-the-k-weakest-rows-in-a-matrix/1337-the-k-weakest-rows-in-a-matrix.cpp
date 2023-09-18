class Solution {
public:
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
int n=mat.size();
int m=mat[0].size();
vector<pair<int,int>>cnt(n);
  for (int i = 0; i < n; ++i) {
      int j=0;
      while(j<m&&mat[i][j])
          j++;
      cnt[i]={j,i};
    }
  sort(cnt.begin(),cnt.end());
  vector<int>ans;
    for (int i = 0; i < k; ++i) {
        ans.push_back(cnt[i].second);
    }
    return ans;
}
};