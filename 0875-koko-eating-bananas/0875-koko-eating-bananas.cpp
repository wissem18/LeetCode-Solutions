class Solution {
public:
int minEatingSpeed(vector<int>& piles, int h) {
int l=1,r=1e9;
while(l<r){
    int mid=(l+r)/2;
    int x=0;
    for (int i = 0; i <piles.size() ; ++i) {
        x+=(piles[i]/mid)+(piles[i]%mid!=0);
        if(x>h)
            break;
    }
    if(x>h)
        l=mid+1;
    else
        r=mid;
}
return l;
}
};