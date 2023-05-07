class Solution {
public:
long long repairCars(vector<int>& ranks, int cars) {
    sort(ranks.begin(),ranks.end());
long long l=1,r=1e14+5;

while(l<=r){
    long long mid=(l+r)/2;
    int x=0;
    for (int i = 0; i < ranks.size(); ++i) {
        x+=int(sqrt(mid/ranks[i]));
        if(x>cars)
            break;
    }
    if(x>=cars){
        r=mid-1;
    }
    else
        l=mid+1;
}
return l;
}
};