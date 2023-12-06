class Solution {
public:
int totalMoney(int n) {
int x=n/7;
int rem=n%7;
return (7*x*(7+x)/2)+(rem*(2*x+1+rem)/2);
}
};