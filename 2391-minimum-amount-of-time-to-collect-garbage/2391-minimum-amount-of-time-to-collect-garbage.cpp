class Solution {
public:
int garbageCollection(vector<string> &garbage, vector<int> &travel) {
   map<char, int> lst;
    int n = travel.size();
    int m=garbage.size();
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < garbage[i].size(); ++j) {
            ans++;
            lst[garbage[i][j]] = i;
        }
    }
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + travel[i];
    }

    for (auto x: lst) {
        ans += pre[x.second];
    }
    return ans;
}
    
};