class Solution {
public:
int findMinDifference(vector<string> &timePoints) {
    vector<int> t;
    for (auto x: timePoints) {
        int h = stoi(x.substr(0, 2));
        int m = stoi(x.substr(3));
        t.push_back(h * 60 + m);
    }
    sort(t.begin(), t.end());
    int ans = 1e9;
    for (int i = 0; i < t.size() - 1; ++i) {
       ans = min(ans,t[i + 1] - t[i]);
    }
    ans=min(ans,1440-(t[t.size()-1]-t[0]));
    return ans;
}
};