class Solution {
public:
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n=A.size();
vector<int>C(n,0);
vector<bool>vis1(n+1,false),vis2(n+1,false);
    for (int i = 0; i < n; ++i) {
     vis1[A[i]]=true;
     vis2[B[i]]=true;
     int cnt=0;
        for (int j = 1; j <=n ; ++j) {
            if(vis1[j]&&vis2[j])
                cnt++;
        }
        C[i]=cnt;
    }
    return C;
}
};