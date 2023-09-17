class Solution {
public:
int shortestPathLength(vector<vector<int>>& graph) {
int n=graph.size();
queue<pair<int,int>>q;
vector<vector<bool>>vis(n,vector<bool>(1<<n,false));
    for (int i = 0; i < n; ++i) {
        q.push({i,1<<i});
        vis[i][1<<i]=true;
    }
    int ans=0;
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int curNode=q.front().first;
            int curState=q.front().second;
            q.pop();
            if(curState==(1<<n)-1)
                return ans;
            for (auto x:graph[curNode]) {
                if(!vis[x][curState|(1<<x)]){
                    vis[x][curState|(1<<x)]=true;
                    q.push({x,curState|(1<<x)});
                }
            }
        }
        ans++;
    }
    return ans;
}
};