class Solution {
public:
    vector<int> evenOddBit(int n) {
    int a=0,b=0;
    int j=0;
    while(n){
        if(n%2){
            if(j)
                b++;
            else
                a++;
        }
        n/=2;
        j^=1;
    }
    vector<int>res={a,b};
    return res;
}
};