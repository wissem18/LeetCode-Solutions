class Solution {
public:
long long continuousSubarrays(vector<int> &nums) {
    long long ans = 0;
    int n = nums.size();
    int i = 0, j = 0;
    multiset<int> s;
    while (i < n) {
        while (j < n) {
            if (!s.empty()) {
                int curmn = min(*s.begin(), nums[j]);
                int curmx = max(*prev(s.end()), nums[j]);
                if (curmx - curmn > 2)
                    break;
            }
            s.insert(nums[j]);
            j++;
        }

        ans += j - i;
        s.erase(s.find(nums[i]));
        i++;
    }
    return ans;

}
};