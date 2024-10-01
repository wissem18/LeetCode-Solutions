class Solution {
public:
bool canArrange(vector<int> &arr, int k) {
   vector<int>occ(k,0);
    for (auto x: arr) {
        occ[((x % k)+k)%k]++;
    }
    if (occ[0] % 2)
        return false;

    for (int i = 1; i < (k+1) / 2; ++i) {
        if (occ[i] != occ[k - i])
            return false;
    }
    if (k % 2 == 0 && occ[k / 2] % 2)
        return false;
    return true;
}
};