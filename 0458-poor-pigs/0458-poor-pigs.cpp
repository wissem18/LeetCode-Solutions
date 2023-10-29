class Solution {
public:
int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
int nbOfTests=minutesToTest/minutesToDie;
int ans=0;
    for (int i = 0; i < 15; ++i) {
        if(pow(nbOfTests+1,ans)>=buckets)
            break;
        ans++;
    }
    return ans;
}
};