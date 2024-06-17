class Solution {
public:
bool judgeSquareSum(int c) {
    for (int i = 0; i <=sqrt(c) ; ++i) {
        int x=c-i*i;
        int sr=sqrt(x);
        if(sr*sr==x)
            return true;
    }
    return false;
}
};