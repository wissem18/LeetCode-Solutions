class Solution {
public:
vector<vector<pair<int,double>>>graph;
vector<bool>vis;
void dfs(int p,int s,double cur,double& ans){
    vis[p]=true;
    if(p==s){
        ans=cur;
        return;
    } 
    for (auto c:graph[p]) {
        if(!vis[c.first]){
           dfs(c.first,s,cur*c.second,ans);   
        }
    }
}
vector<double>
calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {

    vector<double> ans;
    map<string, int> h;
    int j = 0;
    for (int i = 0; i < equations.size(); ++i) {
        if(!h.count(equations[i][0])){
            h[equations[i][0]]=j++;
        }
        if(!h.count(equations[i][1])){
            h[equations[i][1]]=j++;
        }
    }
    graph.resize(j);
    for (int i = 0; i < equations.size(); ++i) {
        graph[h[equations[i][0]]].push_back({h[equations[i][1]],values[i]});
        graph[h[equations[i][1]]].push_back({h[equations[i][0]],1/values[i]});
    }
    for (auto q:queries) {
        if(!h.count(q[0])||!h.count(q[1])){
            ans.push_back(-1.0);
        }
        else if(q[0]==q[1])
            ans.push_back(1.0);
        else{
            vis.assign(j, false);
            double x;
            dfs(h[q[0]],h[q[1]],1.0,x);
            if(vis[h[q[1]]])
                ans.push_back(x);
            else
                ans.push_back(-1.0);

        }
    }
    return ans;
}};