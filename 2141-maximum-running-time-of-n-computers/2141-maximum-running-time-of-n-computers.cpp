class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
long long sum=0;
    for (int i = 0; i < batteries.size(); ++i) {
        sum+=batteries[i];
    }
    long long l=1,r=sum/n;
    while(l<r){
        long long mid=r-(r-l)/2;
        long long cur=0;
        for (int i = 0; i < batteries.size(); ++i) {
            cur+=min((long long) batteries[i],mid);
        }
        if(cur>=n*mid){
           l=mid;
        }
        else
            r=mid-1;
    }
    return l;
}
};