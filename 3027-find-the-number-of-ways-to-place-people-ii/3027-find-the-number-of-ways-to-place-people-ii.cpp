class Solution {
public:
int numberOfPairs(vector<vector<int>>& points) {
    int n=points.size();
    int ans=0;
    sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b){if(a[0]==b[0])return a[1]>b[1];
    return a[0]<b[0];});
    for (int i = 0; i < n; ++i) {
        int y=points[i][1];
        int mx=INT_MIN;
        for (int j = i+1; j < n; ++j) {
            if(i==j||points[i][0]>points[j][0]||points[i][1]<points[j][1])continue;
            if(points[j][1]>mx){
                ans++;
                mx=points[j][1];
            }
        }
    }
    return ans;
}
};