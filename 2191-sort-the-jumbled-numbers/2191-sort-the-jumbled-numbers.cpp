class Solution {
public:
vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
    vector<pair<pair<int, int>, int>> a;
    for (int i = 0; i < nums.size(); ++i) {
        string mapped = to_string(nums[i]);
        for (int j = 0; j < mapped.size(); ++j) {
            mapped[j] = mapping[mapped[j] - '0']+'0';
        }
        a.push_back({{stoi(mapped), i}, nums[i]});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < nums.size(); ++i) {
        nums[i] = a[i].second;
    }
    return nums;
}
};