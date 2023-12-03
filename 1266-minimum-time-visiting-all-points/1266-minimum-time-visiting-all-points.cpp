class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
int ans=0;
    for (int i = 1; i <points.size() ; ++i) {
        int dx=abs(points[i-1][0]-points[i][0]);
        int dy=abs(points[i-1][1]-points[i][1]);
        ans+=min(dx,dy)+abs(dx-dy);
    }
    return ans;
}
};