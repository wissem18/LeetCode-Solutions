class Solution {
public:
int numberOfPairs(vector<vector<int>>& points) {
int n=points.size();
int ans=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i==j||points[i][0]>points[j][0]||points[i][1]<points[j][1])continue;
            bool test=true;
            for (int k = 0; k < n; ++k) {
                if(k==i||k==j)continue;
                if(points[k][0]>=points[i][0]&&points[k][0]<=points[j][0]&&points[k][1]<=points[i][1]&&points[k][1]>=points[j][1]){
                    test= false;
                    break;
                }
            }
            if(test)
                ans++;
        }
    }
    return ans;
}
};