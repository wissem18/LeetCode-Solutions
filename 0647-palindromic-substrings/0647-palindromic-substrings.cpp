class Solution {
public:
int countSubstrings(string s) {
int n=s.size();
vector<vector<int>>isPal(n,vector<int>(n,0));
    
    int ans=s.size();
    for (int i = n-1; i >=0; --i) {
        isPal[i][i]=1;
        for (int j = i+1; j < n; ++j) {
             if(s[i]==s[j]&&(j-i==1|| isPal[i+1][j-1])){
                 ans++;
                 isPal[i][j]=1;
             }
        }
    }
    return ans;
}
};