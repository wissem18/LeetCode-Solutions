class Solution {
public:
vector<int> ans;

void gen(int cur, int &n) {
    if (cur > n)
        return;
    ans.push_back(cur);
    for (int i = 0; i <= 9; ++i) {
        int nxt = cur * 10 + i;
        if (nxt <= n)
            gen(nxt, n);
        else
            break;
    }
}

vector<int> lexicalOrder(int n) {
    for (int i = 1; i <= 9; ++i) {
        gen(i,n);
    }
    return ans;
}
};