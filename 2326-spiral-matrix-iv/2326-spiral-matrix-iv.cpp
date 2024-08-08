/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>>ans(m,vector<int>(n, -1));
    vector<vector<bool>>vis(m,vector<bool>(n, false));
    int x=0,y=0,dir=0;
   while(head) {
        ans[x][y]=head->val;
        vis[x][y]=true;
        int newx=x+dx[dir];
        int newy=y+dy[dir];
        if(newx>=0&&newx<m&&newy>=0&&newy<n&&!vis[newx][newy]){
            x=newx;
            y=newy;
        }
        else{
            dir=(dir+1)%4;
            x=x+dx[dir];
            y=y+dy[dir];
        }
        head=head->next;
    }
    return ans;
}
};