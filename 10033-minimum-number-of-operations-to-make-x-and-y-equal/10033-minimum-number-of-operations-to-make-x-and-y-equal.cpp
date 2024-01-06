class Solution {
public:
vector<int> mem;

int dp(int x, int &y) {
    if (x <= y)
        return y - x;
    if (mem[x] != -1)
        return mem[x];
    int ans = 1e9;
    ans = min(ans, 1 + dp(x - 1, y));
    if (x % 11 == 0)
        ans = min(ans, 1 + dp(x / 11, y));
    if (x % 5 == 0)
        ans = min(ans, 1 + dp(x / 5, y));
    
    int r11 = ((x + 10) / 11) * 11 - x;
    int r5 = ((x + 4) / 5) * 5 - x;
    ans = min(ans, r11+1 + dp((x + r11)/11, y));
    ans = min(ans, r5+1 + dp((x + r5)/5, y));
    return mem[x] = ans;
}

int minimumOperationsToMakeEqual(int x, int y) {
    mem.assign(x+15, -1);
    return dp(x, y);
}
};