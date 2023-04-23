class Solution {
public:
 vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
     vector<vector<int>>result;
     int i=0;
     int n=intervals.size();
     while(i<n){
         int l=intervals[i][0];
         int r=intervals[i][1];
         int j=i+1;
             while(j<n&&intervals[j][0]<=r){
              r=max(intervals[j][1],r);
              j++;
             }
             i=j;
             vector<int>a(2);
             a[0]=l;
             a[1]=r;
             result.push_back(a);
              }
     return result;
    }
};