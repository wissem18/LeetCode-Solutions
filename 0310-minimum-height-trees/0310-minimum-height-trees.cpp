class Solution {
public:
 vector<vector<int>> adj;
vector<bool> vis;
int maxD, maxNode;

void dfs(int x, int d) {
    vis[x] = true;
    if (d > maxD) {
        maxD = d;
        maxNode = x;
    }
    for (auto child: adj[x]) {
        if (!vis[child])
            dfs(child, d + 1);
    }
}

int bfs(int node1,int node2,int dist1,int dist2,int &n){
   unordered_map<int,int>occ;
   queue<int>q;
   int cur=0;
   vis.assign(n,false);
   q.push(node1);
   while(!q.empty()){
       int sz=q.size();
       while(sz--){
           int top=q.front();
           q.pop();
           vis[top]=true;
           if(cur==dist1)
               occ[top]++;
           if(cur>dist1)
               break;
           for (auto c:adj[top]) {
              if(!vis[c])
                  q.push(c);
           }
       }
       cur++;
   }
    vis.assign(n,false);
    queue<int>q1;
    cur=0;
    q1.push(node2);
    while(!q1.empty()){
        int sz=q1.size();
        while(sz--){
            int top=q1.front();
            q1.pop();
            vis[top]=true;
            if(cur==dist2)
                occ[top]++;
            if(cur>dist2)
                break;
            for (auto c:adj[top]) {
                if(!vis[c])
                    q1.push(c);
            }
        }
        cur++;
    }
    for (auto x:occ) {
       if(x.second==2)
           return x.first;
    }
    return 0;
}
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    adj.resize(n);
    for (auto e: edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vis.assign(n,false);
    maxD=-1;
    dfs(0,0);
    int node1=maxNode;
    vis.assign(n,false);
    maxD=-1;
    dfs(maxNode,0);
    int node2=maxNode;
    int dist=maxD+1;
    vector<int>ans;
    if(dist%2){
        ans.push_back(bfs(node1,node2,dist/2,dist/2,n));
    }
    else{
        ans.push_back(bfs(node1,node2,dist/2,(dist/2)-1,n));
        ans.push_back(bfs(node1,node2,(dist/2)-1,dist/2,n));
    }
    return ans;
}
};