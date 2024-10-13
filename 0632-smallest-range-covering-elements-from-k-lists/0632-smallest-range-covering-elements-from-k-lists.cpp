class Solution {
public:
vector<int> smallestRange(vector<vector<int>> &nums) {
    vector<pair<int, int>> all;
    int k = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums[i].size(); ++j) {
            all.push_back({nums[i][j], i});
        }
    }
    sort(all.begin(), all.end());
    int i = 0, j = 0;
    unordered_set<int> s;
    unordered_map<int, int> cnt;
    int n = all.size();
    int l = 0, r = 0;
    int range = 1e9;
    while (j < n) {
        while (s.size() < k && j < n) {
            cnt[all[j].second]++;
            s.insert(all[j].second);
            j++;
        }

        while (i < n && s.size() == k) {
            cnt[all[i].second]--;
            if (cnt[all[i].second] == 0) {
                s.erase(all[i].second);
            }
            i++;
        }
        int left = all[i - 1].first;
        int right = all[j - 1].first;
        if (right - left < range) {
            range = right - left;
            l = left;
            r = right;
        }
    }
    return {l, r};
}
};