class Solution {
public:
    int maximumRequests(int n, vector<vector<int>> &requests) {
        int ans = 0;
        int m = requests.size();
        for (int mask = 0; mask < (1 << m); mask++) {
            vector<int> indegree(n, 0);
            int cnt = __builtin_popcount(mask);
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    indegree[requests[i][0]]--;
                    indegree[requests[i][1]]++;
                }
            }

            bool test = true;
            for (int i = 0; i < n; i++) {
                if (indegree[i]) {
                    test = false;
                    break;
                }
            }

            if (test) {
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};