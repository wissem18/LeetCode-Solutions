# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Binary Search 
# Approach
<!-- Describe your approach to solving the problem. -->
the idea is to maximise the index element in the array and decrease the left and right adjacent elements until we reach 1 and make all the rest element 1 this array will give the minimum sum of elements under the constraints and with index value equal to M, the sum must be <= maxSum .
So we use the binary search to get the maximum possible M that the sum of the elements of the constructed array is <= maxSum.
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
O(logN)
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
O(1)
# Code
```
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
```
