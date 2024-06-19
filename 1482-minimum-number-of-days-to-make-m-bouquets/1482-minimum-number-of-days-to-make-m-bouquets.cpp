class Solution {
public:
int minDays(vector<int>& bloomDay, int m, int k) {
int n=bloomDay.size();
if(m*1LL*k>n)
    return -1;
int l=1,r=1e9;
while(l<r){
    int mid=(l+r)/2;
    int cur=0;
    int grp=0;
    for (int i = 0; i < n; ++i) {
        if(bloomDay[i]<=mid){
            cur++;
        }
        if(cur==k){
            grp++;
            cur=0;
        }
        if(bloomDay[i]>mid){
            cur=0;
        }
    }
    if(grp>=m)
        r=mid;
    else
        l=mid+1;
}
return l;
}
};