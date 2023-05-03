class Solution {
public:
int maxSatisfaction(vector<int>& satisfaction) {
sort(satisfaction.begin(),satisfaction.end());
int ans=0;
int n=satisfaction.size();
int cur_sum=0;
    for (int i = n-1; i >= 0; --i) {
     ans=max(ans,ans+satisfaction[i]+cur_sum);
     cur_sum+=satisfaction[i];
    }
    return ans;
}
};