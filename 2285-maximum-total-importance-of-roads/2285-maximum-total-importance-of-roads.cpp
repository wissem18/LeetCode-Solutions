class Solution {
public:
long long maximumImportance(int n, vector<vector<int>> &roads) {
    vector<int> conn(n, 0);
    for (auto x: roads) {
         conn[x[0]]++;
         conn[x[1]]++;
    }
    sort(conn.begin(),conn.end());
    long long ans=0;
    for (int i = 1; i <=n ; ++i) {
        ans+=conn[i-1]*1LL*i;
    }
    return ans;
}
};