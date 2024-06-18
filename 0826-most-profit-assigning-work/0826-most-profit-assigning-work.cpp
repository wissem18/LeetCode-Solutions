class Solution {
public:
int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
    vector<pair<int, int>> a;
    int n = difficulty.size();
    int m = worker.size();
    for (int i = 0; i < n; ++i) {
        a.push_back({difficulty[i], profit[i]});
    }
    sort(worker.begin(),worker.end());
    sort(a.begin(),a.end());
    int mx=0; 
    int ans=0;
    int j=0;
    for (int i = 0; i < m; ++i) {
      int cur=worker[i];
      while(j<n&&a[j].first<=cur){
          mx=max(mx,a[j].second);
          j++;
      }
      ans+=mx;
    }
    return ans;
}
};