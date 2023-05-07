class Solution {
public:
   int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    int n=reward1.size();
vector<pair<int,int>>ben(n);
    for (int i = 0; i < n; ++i) {
        ben[i]={reward2[i]- reward1[i],i};
    }
    sort(ben.begin(),ben.end());
    int ans=0;
    for (int i = 0; i < k; ++i) {
        ans+=reward1[ben[i].second];
    }
    for (int i = k; i <n ; ++i) {
        ans+=reward2[ben[i].second];
    }
    return ans;
}
};