class Solution {
public:
vector<vector<int>> adj;
map<int, set<int>> contains;

bool share(int i, int j, vector<vector<int>> &routes) {
    int  x=0,y=0;
    while(x<routes[i].size()&&y<routes[j].size()){
        if(routes[i][x]==routes[j][y])
            return true;
        if(routes[i][x]<routes[j][y])
            x++;
        else
            y++;
    }
    return false;
}
vector<bool>vis;
int bfs(int source, int target) {
    if(source==target)
        return 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < adj.size(); ++i) {
        if (contains[i].count(source))
            q.push({1, i});
    }
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        vis[cur.second]=true;
        if(contains[cur.second].count(target))
            return cur.first;
        for (auto x:adj[cur.second]) {
         if(vis[x])continue;
         q.push({cur.first+1,x});
        }
    }
    return -1;
}

int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
    int n = routes.size();
    adj.resize(n);
    for (int i = 0; i < n; ++i) {
        sort(routes[i].begin(),routes[i].end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (share(i, j, routes)) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < routes[i].size(); ++j) {
            contains[i].insert(routes[i][j]);
        }
    }
vis.assign(n,false);
return bfs(source,target);
}
};