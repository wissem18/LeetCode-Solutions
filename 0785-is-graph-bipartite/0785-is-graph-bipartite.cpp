class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int>color(n,0);
    queue<int>q;
    for (int i = 0; i < n; ++i) {
     if(!color[i]){
         q.push(i);
         color[i]=1;
         while(!q.empty()){
                int p=q.front();
                q.pop();
             for (auto x:graph[p]) {
                  if(!color[x]){
                     color[x]=(color[p]==1?2:1);
                         q.push(x);
                  }
                  else if(color[x]==color[p])
                      return false;
               
             }
         }
     }

    }
    return true;
}
};