class Solution {
public:
vector<int> dailyTemperatures(vector<int>& temperatures) {
vector<vector<int>>pos(101);
    for (int i = 0; i < temperatures.size(); ++i) {
        pos[temperatures[i]].push_back(i);
    }
    vector<int>ans;
    for (int i = 0; i < temperatures.size(); ++i) {
        int x=temperatures[i];
        int cur=1e9;
        for (int j = x+1; j <=100 ; ++j) {
            int ind= upper_bound(pos[j].begin(),pos[j].end(),i)-pos[j].begin();
            if(ind!=pos[j].size()){
                cur=min(cur,pos[j][ind]);
            }
        }
        if(cur==1e9)
            ans.push_back(0);
        else
            ans.push_back(cur-i);
    }
    return ans;
}
};