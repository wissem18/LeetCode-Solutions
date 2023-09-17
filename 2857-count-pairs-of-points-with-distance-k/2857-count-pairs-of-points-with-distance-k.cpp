class Solution {
public:
int countPairs(vector<vector<int>> &coordinates, int k) {
    map<pair<int, int>, long long> occ;
    int n = coordinates.size();
    for (int i = 0; i < n; ++i) {
        occ[{coordinates[i][0],coordinates[i][1]}]++;
    }
    long long ans=0;
    for (int i = 0; i < n; ++i) {
        int a=coordinates[i][0],b=coordinates[i][1];
        for (int j = 0; j <=k ; ++j) {
            int x=a^j;
            int y=b^(k-j);
            if(occ.count({x,y}))
                ans+=occ[{x,y}];
             if(x==a&&y==b)
                ans--;
        }
    }
    return ans/2;
}
};