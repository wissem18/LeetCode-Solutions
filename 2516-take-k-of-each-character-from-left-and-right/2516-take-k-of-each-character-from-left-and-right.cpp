class Solution {
public:
int takeCharacters(string s, int k) {
    if (k == 0)
        return 0;
    int n = s.size();
    vector<int> occ(3, 0);
    int l = 0, r = n - 1;
    while (l < n) {
        occ[s[l] - 'a']++;
        l++;
    }
    for (int i = 0; i < 3; ++i) {
        if (occ[i] < k)
            return -1;
    }

    l--;
    while (l >= 0 && min({occ[0], occ[1], occ[2]}) >= k)
        occ[s[l--] - 'a']--;
    int ans = l + 2;
    while (l >= 0) {
        while (r > l && min({occ[0], occ[1], occ[2]}) < k)
            occ[s[r] - 'a']++, r--;
        ans = min(ans, l + n - r);
        occ[s[l] - 'a']--;
        l--;
    }
    while (r >=0 && min({occ[0], occ[1], occ[2]}) < k)
        occ[s[r] - 'a']++, r--;
    ans=min(ans,n-r-1);
    return ans;
}

};