class Solution {
public:
int findMaxLength(vector<int> &nums) {
    int ans = 0;
    int cur = 0;
    int n = nums.size();
    unordered_map<int, int> firstpos;
    for (int i = 0; i < n; ++i) {
        cur +=(nums[i]) ? 1 : -1;
        if (!firstpos.count(cur))
            firstpos[cur] = i;
        if (cur == 0)
            ans = max(ans, i + 1);
        else if(firstpos.count(cur))
            ans = max(ans, i - firstpos[cur] );

    }
    return ans;
}
};