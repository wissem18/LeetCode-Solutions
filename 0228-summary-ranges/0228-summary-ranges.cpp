class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
int n=nums.size();
int i=0;
vector<string>ans;
while(i<n){
string cur= to_string(nums[i]);
int j=i+1;
while(j<n&&nums[j-1]+1==nums[j])
    j++;
if(j-1>i){
    cur+="->"+ to_string(nums[j-1]);
}
ans.push_back(cur);
i=j;
}
return  ans;
}
};