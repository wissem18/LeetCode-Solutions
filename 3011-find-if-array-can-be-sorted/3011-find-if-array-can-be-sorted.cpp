class Solution {
public:
bool canSortArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    int i = 0;
    while (i < n) {
        int j = i + 1;
        multiset<int> s;
        s.insert(nums[i]);
        int cnt = __builtin_popcount(nums[i]);
        while (j < n && __builtin_popcount(nums[j]) == cnt) {
            s.insert(nums[j]);
            j++;
        }
        int k = i;
        for (auto x: s) {
            if (x != temp[k])
                return false;
            k++;
        }
        i=j;
    }
    return true;
}
};