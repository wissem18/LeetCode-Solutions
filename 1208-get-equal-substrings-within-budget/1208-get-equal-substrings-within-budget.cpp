class Solution {
public:
int equalSubstring(string s, string t, int maxCost) {
    int n = s.size();
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        a[i + 1] = a[i] + abs(s[i] - t[i]);
    }
   int ans=0;
    for (int i = 0; i < n; ++i) {
        int x=upper_bound(a.begin(),a.end(),a[i]+maxCost)-a.begin();
        ans=max(ans,x-i-1);
    }
    return ans;
}
};