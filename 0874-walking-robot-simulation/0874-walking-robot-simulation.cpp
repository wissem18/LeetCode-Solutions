class Solution {
public:
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    set<pair<int, int>> st;
    for (int i = 0; i < obstacles.size(); ++i) {
        st.insert({obstacles[i][0], obstacles[i][1]});
    }
    int dir = 0;
    int x = 0, y = 0;
    int ans=0;
    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == -1)
            dir = (dir + 1) % 4;
        else if (commands[i] == -2)
            dir = (dir + 3) % 4;
        else {
            for (int j = 0; j < commands[i]; ++j) {
                if (st.count({x+dx[dir], y+dy[dir]}))
                    break;
                x += dx[dir];
                y += dy[dir];
                ans=max(ans,x * x + y * y);
            }
        }
    }
    return ans;
}
};