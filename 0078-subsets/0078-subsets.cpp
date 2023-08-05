class Solution {
public:
vector<vector<int>>ans;
void rec(int i,vector<int>& nums,vector<int>a){
    if(i==nums.size()){
        ans.push_back(a);
        return;
    }
    rec(i+1,nums,a);
    a.push_back(nums[i]);
    rec(i+1,nums,a);
    a.pop_back();
}
vector<vector<int>> subsets(vector<int>& nums) {
vector<int>a;
rec(0,nums,a);
return ans;
}
};