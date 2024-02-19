class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        int x=log2(n);
        if(n==pow(2,x))
            return true;
        return false;
    }
};