class Solution {
public:
vector<int>mem;
vector<int>ans;
void dp(int i,vector<int>&cur,vector<int>&nums){
    if(i==nums.size()){
        if(cur.size()>ans.size())
            ans=cur;
        return;
    }
    dp(i+1,cur,nums);
    if((cur.empty()||nums[i]%cur.back()==0)&&mem[i]<cur.size()+1){
        mem[i]=cur.size()+1;
        cur.push_back(nums[i]);
        dp(i+1,cur,nums);
        cur.pop_back();
    }
}
vector<int> largestDivisibleSubset(vector<int> &nums) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    mem.assign(n,0);
    vector<int>cur;
    dp(0,cur,nums);
    return ans;
}
};