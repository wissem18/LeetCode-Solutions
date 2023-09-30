class Solution {
public:
 vector<vector<int>>adj;
vector<long long>sum;
int ans=1;
void dfs(int node ,int parent,vector<int>& values){
    sum[node]=values[node];
    for (auto child:adj[node]) {
        if(child!=parent){
            dfs(child,node,values);
            sum[node]+=sum[child];
        }
    }
}
void dfs1(int node ,int parent,int k){
    for (auto child:adj[node]) {
        if(child!=parent){
            dfs1(child,node,k);
            if(sum[child]%k==0)
                ans++;
        }
    }
}
int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
adj.resize(n);
    for (auto e:edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    sum.resize(n);
    dfs(0,-1,values);
    dfs1(0,-1,k);
    return ans;

}
};