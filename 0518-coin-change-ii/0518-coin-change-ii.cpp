class Solution {
public:
vector<vector<int>> mem;

int dp(int i, int cur, int &amount, vector<int> &coins) {
    if (i == coins.size()) {
        return cur == amount;
    }
    if (mem[i][cur] != -1)
        return mem[i][cur];
    int ans = 0;
    for (int j = 0; j <= 5000; ++j) {
        if (cur + j * coins[i] > amount)
            break;
        ans += dp(i + 1, cur + j * coins[i], amount, coins);
    }
    return mem[i][cur] = ans;

}

int change(int amount, vector<int> &coins) {
    int n = coins.size();
    mem.assign(n + 1, vector<int>(amount + 1, -1));
    return dp(0, 0, amount, coins);
}
};