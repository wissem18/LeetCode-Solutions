class Solution {
public:
vector<vector<int>> mem;

int dp(int i, int cur, int &amount, vector<int> &coins) {
    if(cur==amount)
        return 1;
    if (i == coins.size()) {
        return 0;
    }
    if (mem[i][cur] != -1)
        return mem[i][cur];
    if(coins[i]>amount-cur)
        return mem[i][cur]=dp(i+1,cur,amount,coins);
    return mem[i][cur]=dp(i,cur+coins[i],amount,coins)+dp(i+1,cur,amount,coins);

}

int change(int amount, vector<int> &coins) {
    int n = coins.size();
    mem.assign(n + 1, vector<int>(amount + 1, -1));
    return dp(0, 0, amount, coins);
}
};