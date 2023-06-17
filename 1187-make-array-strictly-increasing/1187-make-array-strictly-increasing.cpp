class Solution {
public:
int n;
int m;
int mem[2005][2005];
int dp(int i,int j,int prev,vector<int> &a,vector<int>&b){
if(i==n)
    return 0;
    j= upper_bound(b.begin(),b.end(),prev)-b.begin();
if(mem[i][j]!=-1)
    return mem[i][j];
int ans=2005;

if(a[i]>prev)
    ans=min(ans,dp(i+1,j,a[i],a,b));
if(j!=m)
   ans= min(ans,1+dp(i+1,j+1,b[j],a,b));
return mem[i][j]=ans;
}
int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
 n=arr1.size();
 m=arr2.size();
 sort(arr2.begin(),arr2.end());
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            mem[i][j]=-1;
        }
    }
int x=dp(0,0,-1,arr1,arr2);
 return (x>=2005)?-1:x;
}
};