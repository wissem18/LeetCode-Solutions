class Solution {
public:
    vector<vector<int>>ans;
void rec(int node,int n,vector<int>&path,vector<vector<int>>& graph){
    if(node==n-1){
        path.push_back(node);
        ans.push_back(path);
        path.pop_back();
        return;
    }
    for (auto next:graph[node]) {
           path.push_back(node);
           rec(next,n,path,graph);
           path.pop_back();
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
int n=graph.size();
vector<int>path;
rec(0,n,path,graph);
return ans;
}
};