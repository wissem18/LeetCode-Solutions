class Solution {
public:
int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
int nbOfTests=minutesToTest/minutesToDie;
int l=0,r=15;
while(l<r){
    int mid=(l+r)/2;
    if(pow(nbOfTests+1,mid)>=buckets)
        r=mid;
    else
        l=mid+1;
}
    return l;
}
};