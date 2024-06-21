class Solution {
public:
int n;
vector<vector<int>> mem;

int dp(int i, int x, vector<int> &customers, vector<int> &grumpy, int &minutes) {
    if (i >= n)
        return 0;
    
    if(mem[i][x]!=-1)
        return mem[i][x];
    int ans = dp(i + 1, x, customers, grumpy, minutes) + (grumpy[i] ? 0 : customers[i]);
    if (!x) {
        int cum = 0;
        for (int j = i; j < min(n, i + minutes); ++j) {
            cum += customers[j];
        }
        ans = max(ans, dp(i + minutes, 1, customers, grumpy, minutes) + cum);
    }
    return mem[i][x]=ans;
}

int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
    n = customers.size();
    mem.assign(n,vector<int>(2,-1));
    return dp(0,0,customers,grumpy,minutes);
}
};