class Solution {
public:
void dfsBuildSize(int node, int parent,vector<vector<int>>&graph,vector<int>&sz)
{
    sz[node]=1;
    for (auto child:graph[node])
    {
        if (child != parent){
            dfsBuildSize(child,node,graph,sz);
            sz[node]+=sz[child];
        }
    }
}
long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    int n=roads.size()+1;
    vector<vector<int> >graph(n+1);
    for (int i = 0; i < roads.size(); ++i) {
        int u=roads[i][0];
        int v=roads[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int>sz(n+1,0);
    dfsBuildSize(0,-1,graph,sz);
    long long ans=0;
    for (int i = 1; i <=roads.size(); ++i) {
        ans+=ceil(sz[i]*1.0/seats);
    }
    return ans;
}
};