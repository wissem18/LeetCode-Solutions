class Solution {
public:
int totalMoney(int n) {
int x=n/7;
int ans=7*x*(7+x)/2;
int rem=n%7;
ans+=rem*(2*x+1+rem)/2;
return ans;
}
};