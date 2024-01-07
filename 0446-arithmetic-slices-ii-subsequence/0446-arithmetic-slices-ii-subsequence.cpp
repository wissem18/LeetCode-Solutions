class Solution {
public:
int numberOfArithmeticSlices(vector<int>& nums) {
map<long long ,int>m[nums.size()];
int ans=0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            long long dif=(long long)nums[i]-nums[j];
            int cnt=m[j].count(dif)?m[j][dif]:0;//the number of sequences of the same dif ending with j
            ans+=cnt;
            m[i][dif]+=cnt+1;//the +1 is for the new sequence {j,i} and cnt of the old sequences that we add i in them 
        }
    }
    return ans;
}
};