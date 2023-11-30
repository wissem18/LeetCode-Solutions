class Solution {
public:
int GrayToBin(int n) {
    int res = n;
    while (n > 0) {
        n >>= 1;
        res ^= n;
    }
    return res;
}

int minimumOneBitOperations(int n) {
    if (!n)
        return n;
    int k = __builtin_clz(n);
    int msb=(1 << (31 - k));
    return msb * 2 - 1 - GrayToBin(n - msb);
}
};