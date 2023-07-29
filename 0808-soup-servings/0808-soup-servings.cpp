class Solution {
public:
    map<pair<int,int>,double>mem;
double dp(int a,int b){
    if(a<=0&&b<=0)
        return 0.5;
    if(a<=0)
        return 1;
    if(b<=0)
        return 0;
    if(mem.count({a,b}))
        return mem[{a,b}];
    return mem[{a,b}]=0.25*(dp(a-100,b)+dp(a-75,b-25)+dp(a-50,b-50)+dp(a-25,b-75));
}
double soupServings(int n) {
if(n<5500)    
return dp(n,n);
 else
     return 1;
}
};