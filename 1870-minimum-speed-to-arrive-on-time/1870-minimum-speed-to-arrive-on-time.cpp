class Solution {
public:
 double check(vector<int>& dist, int s){
    double time = 0.0;
    for (int i = 0 ; i < dist.size(); i++) {
        double t =  dist[i]*1.0 /  s;
        time += (i == dist.size() - 1 ? t : ceil(t));
    }
    return time;
}
int minSpeedOnTime(vector<int>& dist, double hour) {
int l=1,r=1e7;
int ans=-1;
while(l<=r){
    int mid=(l+r)/2;
    if(check(dist,mid)<=hour){
        r=mid-1;
        ans=mid;
    }
    else{
        l=mid+1;
    }
}
return ans;
}
};