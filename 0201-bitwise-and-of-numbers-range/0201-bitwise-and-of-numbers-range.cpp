class Solution {
public:
int rangeBitwiseAnd(int left, int right) {
int ans=0;
    for (int i = 0; i < 32; ++i) {
        if((left&(1<<i))&&(right&(1<<i))&&right-left<(1<<i))
            ans+=(1<<i);
    }
    return ans;
}
};