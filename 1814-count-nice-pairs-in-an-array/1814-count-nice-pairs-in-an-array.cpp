class Solution {
public:
    int MOD = 1e9 + 7;
int rev(int x) {
    string s = to_string(x);
    reverse(s.begin(),s.end());
    return stoi(s);
}
int countNicePairs(vector<int>& nums) {
map<int,int>occ;
    for (auto c:nums) {
     occ[c-rev(c)]++;
    }
    int ans=0;
    for (auto x:occ) {
      ans=(ans+x.second*1LL*(x.second-1)/2)%MOD;
    }
    return ans;
}

};