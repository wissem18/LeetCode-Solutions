class Solution {
public:
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
int cnt=0;
int ans=0;
    for (int i = 0; i < mat.size(); ++i) {
        int cur=0;
        for (int j = 0; j < mat[i].size(); ++j) {
            if(mat[i][j]==1)
                cur++;
        }
        if(cur>cnt){
            cnt=cur;
            ans=i;
        }
    }
    vector<int>res;
    res.push_back(ans);
    res.push_back(cnt);
    return res;
}
};