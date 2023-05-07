class Solution {
public:
   int maxCount(vector<int>& banned, int n, int maxSum) {
sort(banned.begin(),banned.end());
  int cur=0;
  int ans=0;
    for (int i = 1; i <=n ; ++i) {
        if(lower_bound(banned.begin(),banned.end(),i)==upper_bound(banned.begin(),banned.end(),i)){
            cur+=i;
            if(cur<=maxSum){
                ans++;
            }
            else
                break;
        }
    }
    return ans;
}
};