class Solution {
public:
    int passThePillow(int n, int time) {
int j=1;
int x=0;
    for (int i = 0; i < time; ++i) {
       if(x==0){
           j++;
           if(j==n){
               x=1-x;
           }
       }
       else{
           j--;
           if(j==1)
               x=1-x;
       }
    }
    return j;
}
};