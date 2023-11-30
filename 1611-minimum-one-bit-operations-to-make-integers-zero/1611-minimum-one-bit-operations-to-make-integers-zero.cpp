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
    return GrayToBin(n);
}
};