class Solution {
public:
int n;
vector<long long>mem;
long long dp(int i,vector<vector<int>>& questions){
    if(i>=n)
    {
        return 0;
    }
    if (mem[i]!=-1){
        return mem[i];
    }

  return mem[i]= max(questions[i][0]+dp(i+1+questions[i][1],questions),dp(i+1,questions));
}
long long mostPoints(vector<vector<int>>& questions) {
n=questions.size();
mem.assign(n,-1);
return dp(0,questions);
}
};