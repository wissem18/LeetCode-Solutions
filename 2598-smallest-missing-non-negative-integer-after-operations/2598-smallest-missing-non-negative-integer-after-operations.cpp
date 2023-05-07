class Solution {
public:
int findSmallestInteger(vector<int>& nums, int value) {
map<int,int>cnt;
for(int i=0;i<nums.size();i++){
    cnt[(nums[i]%value+value)%value]++;
}
for(int i=0;i<nums.size();i++){
    if(cnt.count(i%value)&&cnt[i%value]>0)cnt[i%value]--;
    else
    return i;
}
return nums.size();
}
};