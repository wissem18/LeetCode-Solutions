class Solution {
public:
int distMoney(int money, int children) {
    if(money<children)
        return -1;
    int ans=0;
    int i;
    for (i = 0; i < children; ++i) {
        if(money>=8&&money-8>=children-i-1){
            ans++;
            money-=8;
        }
        else break;
    }
    if((i==children-1&&money==4)||(i==children&&money))
        ans--;
    return ans;
}
};