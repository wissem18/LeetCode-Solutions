class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
vector<int>res;
    for (int i = 0; i < nums.size(); ++i) {
        string x= to_string(nums[i]);
        for (int j = 0; j < x.size(); ++j) {
            res.push_back(x[j]-'0');
        }
    }
    return res;
}
};