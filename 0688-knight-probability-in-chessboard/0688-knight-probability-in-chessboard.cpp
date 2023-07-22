class Solution {
public:
vector<int> di = {1, 1, -1, -1,2,2,-2,-2};
vector<int> dj = {2, -2, -2, 2,1,-1,1,-1};
vector<vector<vector<double>>>mem;
double dp(int i,int j,int k,int&row,int &col,int &n){
    if(k==0){
        return (i==row&&j==col);
    }
    if(mem[i][j][k]!=-1)
        return mem[i][j][k];
    double ans=0;
    for (int l = 0; l < 8; ++l) {
        int x=i-di[l];
        int y=j-dj[l];
        if(x>=0&&x<n&&y>=0&&y<n)
            ans+=dp(x,y,k-1,row,col,n)/8.0;
    }
    return mem[i][j][k]=ans;
}
double knightProbability(int n, int k, int row, int column) {
mem.assign(n,vector(n,vector<double>(k+1,-1)));
double ans=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans+=dp(i,j,k,row,column,n);
        }
    }
    return ans;
}
};