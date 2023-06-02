class Solution {
public:
vector<vector<int>>graph;
vector<bool>vis;
void dfs(int s,int &cnt){
    vis[s]=true;
    cnt++;
    for (auto c:graph[s]) {
     if(!vis[c])
         dfs(c,cnt);
    }
}
int maximumDetonation(vector<vector<int>>& bombs) {
    int n=bombs.size();
graph.resize(n);
    for (int i = 0; i < n; ++i) {
        int x0=bombs[i][0];
        int y0=bombs[i][1];
        int r0=bombs[i][2];
        for (int j = 0; j < n; ++j) {
            if(i==j)
                continue;
            int x1=bombs[j][0];
            int y1=bombs[j][1];
            if(((x0-x1)*1LL*(x0-x1)+(y0-y1)*1LL*(y0-y1))<=r0*1LL*r0){
                graph[i].push_back(j);
            }
        }
    }
    int ans=0;
vis.assign(n,false);
    for (int i = 0; i < n; ++i) {
            int res=0;
        vis.assign(n,false);
            dfs(i,res);
            ans=max(ans,res);
    }
    return ans;
}
};