class Solution {
public:
  long long putMarbles(vector<int>& weights, int k) {
int n=weights.size();
vector<long long>p;
    for (int i = 0; i < n-1; ++i) {
        p.push_back(weights[i]+weights[i+1]);
    }
    sort(p.begin(),p.end());
    long long mx=weights[0]+weights[n-1],mn=weights[0]+weights[n-1];
    for (int i = 0; i < k-1; ++i) {
        mn+=p[i];
        mx+=p[n-2-i];
    }
    return mx-mn;
}
};