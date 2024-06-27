class Solution {
public:
int findCenter(vector<vector<int>> &edges) {
    unordered_map<int, int> m;
    for (int i = 0; i < 2; ++i) {
        m[edges[i][0]]++;
        m[edges[i][1]]++;
    }
    for (auto x: m) {
         if(x.second==2)
             return x.first;
    }
    return -1;
}
};