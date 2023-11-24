class Solution {
public:
int maxCoins(vector<int>& piles) {
    int n=piles.size()/3;
sort(piles.rbegin(), piles.rend());
int ans=0;
    for (int i = 1,cnt=0; cnt<n ; i+=2,cnt++) {
        ans+=piles[i];
    }
    return ans;
}
};