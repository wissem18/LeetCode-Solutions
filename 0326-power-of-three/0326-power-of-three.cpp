class Solution {
public:
bool isPowerOfThree(int n) {
    if(n==1)
        return true;
    if(n<=0)
        return false;
    int a=log2(n)/log2(3);
    double b=log2(n)/log2(3);
    return(abs(a-b)<=1e-12);
}
};