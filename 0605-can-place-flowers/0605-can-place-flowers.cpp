class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int k=0,i=0;
    while(i<flowerbed.size()){
        if(flowerbed[i]==1)
            i++;
           
        else if(flowerbed[i]==0){
             bool u=true,d=true;
            if(i+1<flowerbed.size())
             u=!flowerbed[i+1];
            if(i-1>=0)
             d=!flowerbed[i-1];
             if(u&&d){
             k++;
             flowerbed[i]=1; 
             }
            i++;
        }
    }
    return k>=n;
}
};