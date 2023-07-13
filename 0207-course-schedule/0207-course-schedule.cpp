class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int>indegree(numCourses);
    vector<vector<int>>adj(numCourses);
        for (auto x:prerequisites) {
         adj[x[1]].push_back(x[0]);
         indegree[x[0]]++;
        }
    queue<int>q;
    for (int i = 0; i < numCourses; ++i) {
        if(!indegree[i])
            q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cnt++;
        for (auto child:adj[cur]) {
              indegree[child]--;
              if(indegree[child]==0)
                  q.push(child);
        }
    }
    return cnt==numCourses;
}
};