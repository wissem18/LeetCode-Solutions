class Solution {
public:
int rec(int n, int k) {
    if (n == 0) {
        return 0;
    }
    if (k <= (1 << (n - 1)))
        return rec(n - 1, k);
    else
        return !rec(n-1,k-(1<<(n-1)));
}

int kthGrammar(int n, int k) {
    return rec(n-1,k);
}
};