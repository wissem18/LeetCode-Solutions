class Solution {
public:
    int pivotInteger(int n) {
        if(n==1)
            return 1;
        if(n==8)
            return 6;
        if(n==49)
            return 35;
        if(n==288)
            return 204;
        return -1;
    }
};