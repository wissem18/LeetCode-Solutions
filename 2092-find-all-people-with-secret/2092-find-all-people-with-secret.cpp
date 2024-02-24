class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
          unordered_map<int, vector<pair<int, int>>> adj;
        for (auto meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            adj[x].emplace_back(t, y);
            adj[y].emplace_back(t, x);
        }
        vector<int> earliest(n, INT_MAX);
        earliest[0] = 0;
        earliest[firstPerson] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({firstPerson, 0});
        while (!q.empty()) {
            auto [person, time] = q.front();
            q.pop();
            for (auto [t, nextPerson] : adj[person]) {
                if (t >= time && earliest[nextPerson] > t) {
                    earliest[nextPerson] = t;
                    q.push({nextPerson, t});
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (earliest[i] != INT_MAX) {
                ans.push_back(i);
            }
        }
        return ans;

    }
};