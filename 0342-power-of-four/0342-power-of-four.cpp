class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
            return true;
        if(n<=0)
            return false;
        double x=log(n)/log(4);
        int y=log(n)/log(4);
      if(x==y)
          return true;
        else
            return false;
    }
};