class Solution {
public:
bool ok(int mid,vector<int>a ,int k){
    int cnt=0;
    int sum=0;
    for (int i = 0; i < a.size(); ++i) {
        if(a[i]>mid)
            return false;
        sum+=a[i];
        if(sum>mid){
            cnt++;
            sum=a[i];
        }
    }
    cnt++;
    return (cnt<=k);
}
int shipWithinDays(vector<int>& weights, int days) {
    int l=1,r=1e8;
    while(l<r){
        int mid=(l+r)/2;
        if(ok(mid,weights,days))
            r=mid;
        else
            l=mid+1;
    }
    return l;
}
};