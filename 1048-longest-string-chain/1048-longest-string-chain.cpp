class Solution {
public:
vector<vector<int>> adj;
vector<bool>vis;
int bfs(int p){
    vis[p]=true;
    queue<pair<int,int>> qu;
    qu.push({p,1});
    int ans=0;
    while(!qu.empty()){
        int x=qu.front().first;
        int d=qu.front().second;
        qu.pop();
        ans=max(ans,d);
        for (int i = 0; i < adj[x].size(); ++i) {
            int y=adj[x][i];
            if(!vis[y]){
                vis[y]=true;
                qu.push({y,d+1});
            }
        }
    }
    return ans;
}
int longestStrChain(vector<string> &words) {
    int n = words.size();
    adj.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (words[i].size() - 1 == words[j].size()) {
                for (int k = 0; k < words[i].size(); ++k) {
                    string cur = words[i].substr(0, k) + words[i].substr(k+1, words[i].size() - k - 1);
                    if (cur == words[j]) {
                        adj[i].push_back(j);
                        break;
                    }
                }
            }
        }
    }

    int ans=0;
    for (int i = 0; i < n; ++i) {
        vis.assign(n,false);
        ans=max(ans, bfs(i));
    }

    return ans;
}
};