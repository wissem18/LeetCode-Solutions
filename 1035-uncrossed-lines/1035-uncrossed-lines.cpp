class Solution {
public:
map<int,vector<int>>mp;
vector<vector<int>>mem;
int dp(int i,int lst,vector<int>& nums1, vector<int>& nums2){
    if(i==nums1.size()+1)
        return 0;
    if(mem[i][lst]!=-1)
        return mem[i][lst];
    if(mp.count(nums1[i-1])){
        int x= upper_bound(mp[nums1[i-1]].begin(),mp[nums1[i-1]].end(),lst)-mp[nums1[i-1]].begin();
        if(x!=mp[nums1[i-1]].size()){
            return mem[i][lst]=max(dp(i+1,lst,nums1,nums2),1+dp(i+1,mp[nums1[i-1]][x],nums1,nums2));
        }
    }
    return mem[i][lst]=dp(i+1,lst,nums1,nums2);
}
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    for (int i = 0; i < nums2.size(); ++i) {
        mp[nums2[i]].push_back(i+1);
    }
    mem.assign(nums1.size()+1,vector<int>(nums2.size()+1,-1));
    return dp(1,0,nums1,nums2);
}
};