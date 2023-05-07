class Solution {
public:
vector<bool> vis;
vector<bool> anc;
int a;
bool isCyclic(int p,vector<int> &edges) {
    
    vis[p] = true;
    anc[p] = true;
    if(edges[p]!=-1){
        int x = edges[p];
        if (vis[x] && anc[x]){
            a=x;
            return true;
            }
        else if(!vis[x])
        return isCyclic(x,edges);
    }
    anc[p] = false;
    return false;
}

int longestCycle(vector<int> &edges) {
    int n=edges.size();
vis.resize(n);
anc.resize(n);
int ans=-1;
    for (int i = 0; i < n; ++i) {
        if(!vis[i]){
            anc.assign(n,false);
            if(isCyclic(i,edges))
              {
                  int l=1;
                  int b=edges[a];
                  while(a!=b){
                      b=edges[b];
                      l++;
                  }
                  ans=max(ans,l);
              }
        }
    }
    return ans;
}

};