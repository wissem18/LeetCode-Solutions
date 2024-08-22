class Solution {
public:
    int findComplement(int num) {
        unsigned mask=1;
        int x=num; 
        while(x){
            mask<<=1;
            x>>=1;
        }
        mask-=1;
        return num^mask;
    }
};