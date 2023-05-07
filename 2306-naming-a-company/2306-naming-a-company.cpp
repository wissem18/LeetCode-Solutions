class Solution {
public:
long long distinctNames(vector<string>& ideas) {
    vector<unordered_set<string>> group(26);
    for (auto &idea : ideas)
        group[idea[0] - 'a'].insert(idea.substr(1));

    long long ans = 0;
    for (int i = 0; i < 25; ++i) {
        for (int j = i + 1; j < 26; ++j) {
            int nb = 0;
            for (auto &idea : group[i])
                nb += group[j].count(idea);

            ans += 2LL * (group[i].size() - nb) * (group[j].size() - nb);
        }
    }

    return ans;
}
};