class Solution {
public:
vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    map<int, pair<int,int>> m;
    vector<int> ans;
    for (int i = 0; i < nums1.size(); ++i) {
        m[nums1[i]].first++;
    }
    for (int i = 0; i < nums2.size(); ++i) {
        m[nums2[i]].second++;
    }
    for (auto &[x,y]:m) {
        for (int i = 0; i < min(y.first,y.second); ++i) {
            ans.push_back(x);
        }
    }
    return ans;
}
};