class Solution {
public:
  map<pair<int,int>,int>mem;
int dp(int i,int j,string&s1,string &s2){
    if(i<0&&j<0){
        return 0;
    }
    if(mem.count({i,j}))
        return mem[{i,j}];
    if(i<0)
        return mem[{i,j}]=int(s2[j])+dp(i,j-1,s1,s2);
    if(j<0)
        return mem[{i,j}]=int(s1[i])+dp(i-1,j,s1,s2);
    if(s1[i]==s2[j])
        return mem[{i,j}]=dp(i-1,j-1,s1,s2);
    else{
        return mem[{i,j}]=min(int(s2[j])+dp(i,j-1,s1,s2),int(s1[i])+dp(i-1,j,s1,s2));
    }
}
int minimumDeleteSum(string s1, string s2) {
int n=s1.size();
    int m=s2.size();
return dp(n-1,m-1,s1,s2);
}
};