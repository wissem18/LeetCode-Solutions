class Solution {
public:
long long minimumTime(vector<int>& time, int totalTrips) {
long long l=1,r=1e14;
while(l<r){
    long long mid=(l+r)/2;
    long long x=0;
    for (int i = 0; i < time.size(); ++i) {
        x+=mid/time[i];
        if(x>totalTrips)
        break;
    }
    if(x>=totalTrips)
        r=mid;
    else
        l=mid+1;
}
return l;
}
};