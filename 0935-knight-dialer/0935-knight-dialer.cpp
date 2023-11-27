class Solution {
public:
int MOD = 1e9+7;
vector<int>adj[10]={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
void multiply(vector<vector<int>>&mat1, vector<vector<int>>&mat2) {
    int R1=mat1.size();
    int R2=mat2.size();
    int C1=mat1[0].size();
    int C2=mat2[0].size();
    vector<vector<int>>res(R1,vector<int>(C2));
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < R2; k++) {
                res[i][j] = (res[i][j]+(mat1[i][k] *1LL* mat2[k][j])%MOD)%MOD;
            }
        }
    }
    mat1=res;
}
void power_matrix(vector<vector<int>>&A, int n) {

    int N=A.size();
    vector<vector<int>>B(N,vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = A[i][j];
        }
    }
    n = n - 1;
    while (n > 0) {
        if (n & 1)
            multiply(A, B);

        multiply(B, B);
        n >>= 1;
    }
}
int knightDialer(int n) {
    if(n==1)
        return 10;
    vector<vector<int>>M(10,vector<int>(10,0));
    for (int i = 0; i < 10; ++i) {
        for (auto x:adj[i]) {
           M[i][x]=1;
        }
    }
    power_matrix(M,n-1);
    int ans=0;
    for (int i = 0; i <10 ; ++i) {
        for (int j = 0; j < 10; ++j) {
            ans=(ans+M[i][j])%MOD;
        }
    }
    return ans;
}
};