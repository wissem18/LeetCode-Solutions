class Solution {
public:
    vector<int> length;
vector<int> cnt;
void dp (int i,vector<int>& nums) {
    if (length[i] != 0)
        return;

    length[i] = 1;
    cnt[i] = 1;
    for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
            dp(j,nums);
            if (length[j] + 1 > length[i]) {
                length[i] = length[j] + 1;
                cnt[i] = 0;
            }
            if (length[j] + 1 == length[i]) {
                cnt[i] += cnt[j];
            }
        }
    }
}
int findNumberOfLIS(vector<int>& nums) {
int n=nums.size();
length.resize(n);
cnt.resize(n);
int mx=0;
    for (int i = 0; i < n; ++i) {
        dp(i,nums);
        if(length[i]>mx)
            mx=length[i];
    }
    int ans=0;
    for (int i = 0; i < n; ++i) {
        if(length[i]==mx)
            ans+=cnt[i];
    }
    return ans;
}
};