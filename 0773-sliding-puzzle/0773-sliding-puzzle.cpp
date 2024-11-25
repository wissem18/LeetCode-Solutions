class Solution {
public:
map<int, vector<int>> transitions;


int slidingPuzzle(vector<vector<int>> &board) {
    transitions[0] = {1, 3};
    transitions[1] = {0, 2, 4};
    transitions[2] = {1, 5};
    transitions[3] = {0, 4};
    transitions[4] = {1, 3, 5};
    transitions[5] = {2, 4};
    string initialState = "123450";

    string finalState = "";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            finalState.push_back(board[i][j] + '0');
        }
    }
    unordered_set<string> vis;
    queue<string> q;
    vis.insert(initialState);
    q.push(initialState);
    int ans = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            string curState = q.front();
            q.pop();
            if (curState == finalState)
                return ans;
            for (int i = 0; i < 6; ++i) {
                if (curState[i] == '0') {
                    for (auto t: transitions[i]) {
                        string next = curState;
                        swap(next[i], next[t]);
                        if (!vis.count(next)) {
                            vis.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
        }
        ans++;
    }
    return -1;
}
};