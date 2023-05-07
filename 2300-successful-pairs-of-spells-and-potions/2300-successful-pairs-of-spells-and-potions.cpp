class Solution {
public:
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
sort(potions.begin(),potions.end());
vector<int>ans;
    for (int i = 0; i < spells.size(); ++i) {
        int x= potions.size()-(lower_bound(potions.begin(),potions.end(),(spells[i]+success-1)/spells[i])-potions.begin());
        ans.push_back(x);
    }
    return ans;
}
};