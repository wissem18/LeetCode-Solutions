class Solution {
public:
vector<vector<long long>> mem;

long long dp(int i, int j,
             vector<int> &robot,
             vector<int> &factoryPositions) {
    if (i == robot.size()) return 0;
    if (j == factoryPositions.size()) return 1e12;

    if (mem[i][j] != -1) return mem[i][j];

    long long assign = abs(robot[i] - factoryPositions[j]) + dp(i + 1, j + 1, robot, factoryPositions);

    long long skip = dp(i, j + 1, robot, factoryPositions);

    return mem[i][j] = min(assign, skip);
}

long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory) {

    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());

    vector<int> factoryPositions;
    for (auto f: factory)
        for (int i = 0; i < f[1]; i++) factoryPositions.push_back(f[0]);

    int robotCount = robot.size(), factoryCount = factoryPositions.size();
    mem.assign(robotCount, vector<long long>(factoryCount, -1));
    return dp(0, 0, robot, factoryPositions);
}
};