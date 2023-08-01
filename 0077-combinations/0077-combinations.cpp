class Solution {
public:
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>>ans;
    for (int i = 0; i < (1<<n); ++i) {
        if(__builtin_popcount(i)==k){
            vector<int>cur;
            for (int j = 0; j <n ; ++j) {
                if(i&(1<<j)){
                    cur.push_back(j+1);
                }
            }
            ans.push_back(cur);
        }
    }
    return ans;
}
};