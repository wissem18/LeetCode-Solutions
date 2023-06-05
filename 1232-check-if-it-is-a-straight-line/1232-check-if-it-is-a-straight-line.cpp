class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
int n=coordinates.size();
    for (int i = 1; i < n-1; ++i) {
        if((coordinates[i+1][1]-coordinates[i][1])*(coordinates[i][0]-coordinates[i-1][0])!=(coordinates[i][1]-coordinates[i-1][1])*(coordinates[i+1][0]-coordinates[i][0]))
            return false;
    }
    return true;
}
};