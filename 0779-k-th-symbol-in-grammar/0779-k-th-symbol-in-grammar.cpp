class Solution {
public:
int rec(int n, int k, int x) {
    if (n == 0) {
        return x;
    }
    if (k <= (1 << (n - 1)))
        return rec(n - 1, k, x);
    else
        return rec(n-1,k-(1<<(n-1)),!x);
}

int kthGrammar(int n, int k) {
    return rec(n-1,k,0);
}
};