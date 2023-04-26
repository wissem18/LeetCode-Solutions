class Solution {
public:
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    queue<vector<int>> q;
    q.push({src,0,0});
    vector<int>dist(n,1e9);
    dist[src]=0;

    while (!q.empty()){
        vector<int> parent = q.front();
        q.pop();
        if(parent[2]>k)
            continue;
        for (int i = 0; i < flights.size(); ++i) {
            if(flights[i][0]!=parent[0])
                continue;
            int next=flights[i][1];
            if(parent[1]+flights[i][2]<dist[next]){
                dist[next]=parent[1]+flights[i][2];
                q.push({next,dist[next],parent[2]+1});
            }
        }
    }
    return dist[dst]==1e9?-1:dist[dst];
}
};