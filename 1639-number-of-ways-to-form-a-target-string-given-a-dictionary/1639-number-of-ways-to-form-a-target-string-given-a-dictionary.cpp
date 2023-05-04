class Solution {
public:
const int MOD=1e9+7;
    int n;
    vector<vector<long long>>mem;
    vector<vector<long long>>cnt;
    long long  dp(int i,int j,string &target){
        if(j==target.size())
            return 1;
        if(i==n)
            return 0;
        if(mem[i][j]!=-1)
            return mem[i][j];

        return mem[i][j]=((cnt[target[j]-'a'][i]*dp(i+1,j+1,target))%MOD+dp(i+1,j,target)%MOD)%MOD;
        }

    int numWays(vector<string>& words, string target) {
     n=words[0].size();
     mem.assign(n,vector<long long>(target.size(),-1));
     cnt.assign(26,vector<long long>(n,0));
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                cnt[words[i][j]-'a'][j]++;
            }
        }
    return dp(0,0,target);
    }
};