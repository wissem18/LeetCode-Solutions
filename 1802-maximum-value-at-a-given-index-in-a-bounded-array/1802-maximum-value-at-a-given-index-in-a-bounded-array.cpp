class Solution {
public:
int maxValue(int n, int index, int maxSum) {
    int l = 1, r = maxSum;
    while (l < r) {
        int mid = (l + r+1) / 2;
//   sum from: mid-1 --> mid-index
//   sum from: mid-1-->mid-n+index+1
        int low = max(1, mid - index);
        int high = max(1, mid - n + index + 1);
        long long sum = mid + (mid - 1 + low) *1LL* (mid - low) / 2 + (mid - 1 + high) * 1LL*(mid - high) / 2 + max(0, index - mid + 1) + max(0, n - index - mid);
        if (sum > maxSum)
            r = mid - 1;
        else
            l = mid;
    }
    return l;
}
};