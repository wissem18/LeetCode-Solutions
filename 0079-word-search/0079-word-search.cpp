class Solution {
public:
bool dfs(int i,string word,int x,int y,vector<vector<char>> &board){
    if(i==word.size())return true;
    if(x<0||y<0||x==board.size()||y==board[0].size()||word[i]!=board[x][y])return false;
    //Do
    board[x][y]+=500;//to mark it visited 
    //Recur
    bool test= dfs(i+1,word,x+1,y,board)||dfs(i+1,word,x-1,y,board)||dfs(i+1,word,x,y+1,board)||dfs(i+1,word,x,y-1,board);
    //Undo
    board[x][y]=word[i]; // mark unvisited 
    return test;
    
}
bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if(dfs(0,word,i,j,board))
                return true;
        }
    }
    return false;
}
};