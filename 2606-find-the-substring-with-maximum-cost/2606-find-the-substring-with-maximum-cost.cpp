class Solution {
public:
 int maximumCostSubstring(string s, string chars, vector<int>& vals) {
vector<int>cost(26);
    for (int i = 0; i < 26; ++i) {
        cost[i]=i+1;
    }
    for (int i = 0; i < chars.size(); ++i) {
        cost[chars[i]-'a']=vals[i];
    }
    int n=s.size();
    vector<int>a(n);
    for (int i = 0; i < s.size(); ++i) {
        a[i]=cost[s[i]-'a'];
    }
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++) {
        sum = max(a[k],sum+a[k]);
        best = max(best,sum);
    }
    return best;

}
};