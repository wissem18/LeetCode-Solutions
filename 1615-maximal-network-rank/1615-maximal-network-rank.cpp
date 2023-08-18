class Solution {
public:

int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<int>deg(n,0);
    vector<vector<bool>>connected(n,vector<bool>(n,false));
    for (int i = 0; i < roads.size(); ++i) {
        connected[roads[i][0]][roads[i][1]]=true;
        connected[roads[i][1]][roads[i][0]]=true;
        deg[roads[i][0]]++;
        deg[roads[i][1]]++;
    }
    int ans=0;
    for (int i = 0; i <n; ++i) {
        for (int j = i+1; j <n ; ++j) {
            ans=max(ans,deg[i]+deg[j]-(connected[i][j]) );
        }
    }
    return ans;
}
};