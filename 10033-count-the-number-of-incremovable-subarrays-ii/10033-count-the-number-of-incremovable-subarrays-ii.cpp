class Solution {
public:
long long incremovableSubarrayCount(vector<int> &nums) {
    long long n = nums.size();
    long long i = 1;
    while (i < n && nums[i] > nums[i - 1]) {
        i++;
    }
    if (i == n)
        return n * (n + 1) / 2;
    else {
        long long l = i;
        long long ans = 0;
//        cout<<"l : "<<l<<endl;
        ans += l + 1;
        i = 1;
        while (i <n && nums[n - i - 1] < nums[n - i]) {
            i++;
        }
        long long r = i;
//cout<<"r : "<<r<<endl;
        ans += r;
        for (int j = 0; j < l; ++j) {
            while(r&&nums[j]>=nums[n-r])r--;
            ans+=r;
        }
        return ans;
    }

}
};