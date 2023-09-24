class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
vector<vector<double>>ans(query_row+2,vector<double>(query_row+2,0));
ans[0][0]=poured;
    for (int i = 0; i <=query_row; ++i) {
        for (int j = 0; j <=i ; ++j) {
            double fall=(ans[i][j]-1.0)/2;
            if(fall>0){
                ans[i+1][j]+=fall;
                ans[i+1][j+1]+=fall;
            }
        }
    }
    return min(1.0,ans[query_row][query_glass]);
}
};