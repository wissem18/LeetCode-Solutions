class Solution {
public:
   int eraseOverlapIntervals(vector<vector<int>>& intervals) {
int n=intervals.size();
sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
   return a[1]<b[1];
});
int ans=0;
int last=INT_MIN;
    for (int i = 0; i <n ; ++i) {
        if(last<=intervals[i][0])
            last=intervals[i][1];
        else
            ans++;
    }
    return ans;
}
};