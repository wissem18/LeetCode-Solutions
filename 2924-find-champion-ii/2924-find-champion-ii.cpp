class Solution {
public:
int findChampion(int n, vector<vector<int>> &edges) {
    vector<int> indegree(n, 0);
    for (auto e: edges) {
        indegree[e[1]]++;
    }
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            cnt++;
            ans = i;
        }
    }
    if (cnt != 1)
        return -1;
    return ans;
}
};