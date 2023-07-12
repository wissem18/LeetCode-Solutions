class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int>indegree(n);
    vector<vector<int>>adj(n);
    for (int i = 0; i < n; ++i) {
        for (auto c:graph[i]) {
         adj[c].push_back(i);
         indegree[i]++;
        }
    }
    vector<bool>safe(n,false);
    queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        safe[cur]=true;
        for (auto child:adj[cur]) {
              indegree[child]--;
              if(indegree[child]==0)
                  q.push(child);
        }
    }
    vector<int>ans;
    for (int i = 0; i < n; ++i) {
        if(safe[i])
            ans.push_back(i);
    }
    return ans;
}
};