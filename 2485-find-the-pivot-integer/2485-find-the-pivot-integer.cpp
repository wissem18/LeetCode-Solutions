class Solution {
public:
    int pivotInteger(int n) {
        int s=n*(n+1)/2;
        for(int i=1;i<=n;i++){
            int l=(i+1)*i/2-i;
            if(s-l-i==l)
                return i;
        }
        return -1;
    }
};