class Solution {
public:

vector<int> findDuplicates(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        nums[nums[i]%(n)] +=n;
    }
    for (int i = 0; i < n; ++i) {
        if((nums[i]/n)==(2+(nums[i]%n==0)))
            if(i==0)
                ans.push_back(i+n);
            else
                ans.push_back(i);
    }
    return ans;
}
};