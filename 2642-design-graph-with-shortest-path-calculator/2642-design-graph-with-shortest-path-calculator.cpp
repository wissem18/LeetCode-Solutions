
    class Graph {
    public:
        vector<pair<int,int>>adj[101];
        int N;
        Graph(int n, vector<vector<int>>& edges) {
            N=n;
            for(auto i:edges){
                adj[i[0]].push_back({i[1],i[2]});
            }
        }

        void addEdge(vector<int> edge) {
            adj[edge[0]].push_back({edge[1],edge[2]});
        }

        int shortestPath(int node1, int node2) {
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            vector<int>d(N+1,1e9);
            d[node1]=0;
            pq.push({0,node1});
            while(!pq.empty()){
                int dist=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto it:adj[node]){
                    if(dist+it.second<d[it.first]){
                        d[it.first]=dist+it.second;
                        pq.push({d[it.first],it.first});
                    }
                }
            }
            if(d[node2]==1e9) return -1;
            return d[node2];
        }
    };

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */