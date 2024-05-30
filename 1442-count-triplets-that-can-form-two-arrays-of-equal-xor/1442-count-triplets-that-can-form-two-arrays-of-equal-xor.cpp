class Solution {
public:
int countTriplets(vector<int> &arr) {
    int n = arr.size();
    vector<int> prexor(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prexor[i + 1] = prexor[i] ^ arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {

        for (int j = i + 1; j < n; ++j) {
            int curxor = prexor[j + 1] ^ prexor[i];
            if (!curxor)
                ans+=j-i;
              
        }
    }
    return ans;
}
};