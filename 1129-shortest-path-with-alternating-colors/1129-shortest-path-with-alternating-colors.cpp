class Solution {
public:
vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<pair<int,int>> graph[n];
    bool visited[n][3];
    vector<int> dist(n,-1);
    memset(visited, false,sizeof visited);
    for (int i = 0; i < redEdges.size(); ++i) {
        graph[redEdges[i][0]].push_back({redEdges[i][1],0});
    }
    for (int i = 0; i < blueEdges.size(); ++i) {
        graph[blueEdges[i][0]].push_back({blueEdges[i][1],1});
    }
        queue<vector<int>> q;
        q.push({0,0,1});
        q.push({0,0,0});
        dist[0]=0;
        while (!q.empty()){
            auto parent = q.front();
            q.pop();
            visited[parent[0]][parent[2]]= true;
            for (auto child:graph[parent[0]])
            {
                if (!visited[child.first][child.second]&&child.second!=parent[2])
                {
                   if(dist[child.first]==-1)
                       dist[child.first]=1+parent[1];
                   q.push({child.first,1+parent[1],child.second});
                }
            }
        }
return dist;
}
};