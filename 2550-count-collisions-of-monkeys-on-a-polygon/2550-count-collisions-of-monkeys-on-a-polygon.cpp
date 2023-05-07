class Solution {
public:
int binpow(long long a, int b, int m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a )% m;
        a = (a * a*1LL) % m;
        b >>= 1;
    }
    return res;
}
int monkeyMove(int n) {
int x=1e9+7;
    return (binpow(2,n,x)-2+x)%x;
}
};