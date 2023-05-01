class Solution {
public:
int BFS(int n,unordered_map<int,vector<int>>m,vector<int>& arr){
    queue<int>q;
    q.push(0);
    vector<bool>vis(n,false);
    vis[0]=true;
    int nb=0;
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
        int cur=q.front();
        q.pop();
        if(cur==n-1)
            return nb;
      vector<int>&curidx=m[arr[cur]];
      curidx.push_back(cur+1);
      curidx.push_back(cur-1);
            for (auto x:curidx) {
              if(x>=0&&x<n&&!vis[x]){
              q.push(x);
              vis[x]=true;
              }
            }
            curidx.clear();
            }
        nb++;
    }
    return -1;
}
int minJumps(vector<int>& arr) {
unordered_map<int,vector<int>>m;
int n=arr.size();
    for (int i = 0; i < n; ++i) {
        m[arr[i]].push_back(i);
    }
    return BFS(n,m,arr);
}
};