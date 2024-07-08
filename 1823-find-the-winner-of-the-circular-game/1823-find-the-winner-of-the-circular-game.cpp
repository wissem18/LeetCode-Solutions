class Solution {
public:
int findTheWinner(int n, int k) {
    vector<int> lost(n, false);
    int cur = 0;
    for (int i = 0; i < n - 1; ++i) {
        int cnt = 0;
        while (cnt < k) {

            if (!lost[cur])
                cnt++;
            cur = (cur + 1) % n;
        }
        lost[(cur - 1 + n) % n] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (!lost[i])
            return i + 1;
    }
    return -1;
}
};