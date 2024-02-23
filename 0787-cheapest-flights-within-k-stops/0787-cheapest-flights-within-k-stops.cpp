class Solution {
public:
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    queue<vector<int>> q;
    q.push({src,0,0});
    vector<int>dist(n,1e9);
    dist[src]=0;
    vector<vector<pair<int,int>>>flight(n);
    for (int i = 0; i < flights.size(); ++i) {
        flight[flights[i][0]].push_back({flights[i][1],flights[i][2]});
    }
    while (!q.empty()){
        vector<int> parent = q.front();
        q.pop();
        if(parent[2]>k)
            continue;
        for (int i = 0; i < flight[parent[0]].size(); ++i) {
            int next=flight[parent[0]][i].first;
            if(parent[1]+flight[parent[0]][i].second<dist[next]){
                dist[next]=parent[1]+flight[parent[0]][i].second;
                q.push({next,dist[next],parent[2]+1});
            }
        }
    }
    return dist[dst]==1e9?-1:dist[dst];
}
};