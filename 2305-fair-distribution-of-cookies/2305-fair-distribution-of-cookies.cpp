class Solution {
public:
    int ans=1e9;
void PartitionSub(int i, int cnt, int n, int k, vector<int> &cookies, vector<vector<int>> &v) {
    if (i >= n) {
        if (cnt == k) {
            int cur = 0;
            for (int j = 0; j < v.size(); ++j) {
                int nb = 0;
                for (int l = 0; l < v[j].size(); ++l) {
                    nb += v[j][l];
                }
                cur = max(cur, nb);
            }
            ans = min(ans, cur);
        }
        return;
    }
    for (int j = 0; j < k; j++) {
        if (!v[j].empty()) {
            v[j].push_back(cookies[i]);
            PartitionSub(i + 1, cnt, n, k, cookies, v);
            v[j].pop_back();
        } else {
            v[j].push_back(cookies[i]);
            PartitionSub(i + 1, cnt+1, n, k, cookies, v);
            v[j].pop_back();
            break;
        }
    }
}

int distributeCookies(vector<int> &cookies, int k) {
    int n = cookies.size();
    vector<vector<int>>v(k+1);
    PartitionSub(0,0,n,k,cookies,v);
    return ans;
}
};