class Solution {
public:
    vector<long long> mem;

long long dp(int msk, vector<int> &mskPerson) {
    if (!msk)
        return 0;
    if (mem[msk] != -1)
        return mem[msk];
    for (int i = 0; i < mskPerson.size(); ++i) {
        int cur = msk & ~mskPerson[i];
        if (cur != msk) {
            long long ansmsk = dp(cur,  mskPerson) | (1LL << i);
            if (mem[msk] == -1 || __builtin_popcountll(ansmsk) < __builtin_popcountll(mem[msk])) {
                mem[msk] = ansmsk;
            }
        }
    }
    return mem[msk];
}


vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people) {
    int n = req_skills.size();
    int m = people.size();
    unordered_map<string, int> id;
    for (int i = 0; i < n; ++i) {
        id[req_skills[i]] = i;
    }
    vector<int> mskPerson(m, 0);
    for (int i = 0; i < m; ++i) {
        for (auto x: people[i]) {
            mskPerson[i] |= (1 << id[x]);
        }
    }
    mem.assign(1<<n,-1);
    vector<int>res;
long long ans=dp((1<<n)-1,mskPerson);
    for (int i = 0; i < m; ++i) {
        if(ans&(1LL<<i))
            res.push_back(i);
    }
    return res;
}
};