class Solution {
public:
  int Bfs (vector<vector<int>>& board,vector<pair<int,int>>&rc){
    queue<int> q;
    q.push(1);
    int n=board.size();
    vector<int>dist(n*n+1,-1);
    dist[1]=0;
    while (!q.empty()){
        int cur = q.front();
        q.pop();

        for (int i=cur+1;i<=min(n*n,cur+6);i++)
        {
            pair<int,int>xy=rc[i];
            int next=board[xy.first][xy.second]==-1?i:board[xy.first][xy.second];
            if (dist[next]==-1)
            {
                q.push(next);

                dist[next]=1+dist[cur];

            }
        }
    }
    return dist[n*n];
}
int snakesAndLadders(vector<vector<int>>& board) {
    int n=board.size();
    vector<pair<int,int>>rc(n*n+1);
    int id=1;
    for (int i = n-1; i >=0 ; --i) {
        if((n-i)%2)
        for (int j = 0; j < n; ++j) {
            rc[id]={i,j};
            id++;
        }
        else
            for (int j = n-1; j >=0 ; --j) {
                rc[id]={i,j};
                id++;
            }
    }
    return Bfs(board,rc);

}
};