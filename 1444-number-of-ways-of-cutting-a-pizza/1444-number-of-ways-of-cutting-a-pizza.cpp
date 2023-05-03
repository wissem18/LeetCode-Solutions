class Solution {
public:
const int MOD = 1e9 + 7;
vector<vector<int>>psa;
int R;
int C;
int mem[50][50][10];
int dp(int i,int j,int k,vector<string>& pizza){
if(!psa[i][j])
    return 0;

    if(k==0){
            return 1;
    }
    if(mem[i][j][k]!=-1)
        return mem[i][j][k];
    int ans=0;
    for (int l = i+1; l < R; ++l) {
       if(psa[i][j]-psa[l][j]>0)
        ans=(ans+dp(l,j,k-1,pizza))%MOD;
    }
    for (int l = j+1; l < C; ++l) {
      if(psa[i][j]-psa[i][l]>0)
        ans=(ans+dp(i,l,k-1,pizza))%MOD;
    }
    return mem[i][j][k]=ans;
}
int ways(vector<string>& pizza, int k) {
    R=pizza.size();
    C=pizza[0].size();
    psa.assign(R+1,vector<int>(C+1,0));
    for (int row = R - 1; row >= 0; row--) {
        for (int col = C - 1; col >= 0; col--) {
            psa[row][col] = (pizza[row][col] == 'A') + psa[row + 1][col] +
                               psa[row][col + 1] - psa[row + 1][col + 1];

        }
    }
    memset(mem,-1,sizeof mem);
    return dp(0,0,k-1,pizza);
}

};