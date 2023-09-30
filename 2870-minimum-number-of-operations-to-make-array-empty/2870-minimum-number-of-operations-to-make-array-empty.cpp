class Solution {
public:
int minOperations(vector<int>& nums) {
    int n=nums.size();
    unordered_map<int,int>cnt;
    int ans=0;
    for (int i = 0; i < n; ++i) {
        cnt[nums[i]]++;
    }
    for(auto x:cnt){
      if(x.second==1)
          return -1;
      ans=ans+(x.second+2)/3;
    }
    return ans;
}
};