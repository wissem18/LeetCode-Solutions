class Solution {
public:
    int minDeletions(string s) {
         vector<int> occ(26);
        int ans=0;
    for (char c: s)
    occ[c - 'a']++;
    sort(occ.begin(),occ.end());
    for (int i = 24; i >= 0 && occ[i] > 0; --i) {
        ans += max(0, occ[i] - max(0, occ[i + 1] - 1));
        occ[i] = min(occ[i], max(0, occ[i + 1] - 1));
    }
    return ans;
    }
};