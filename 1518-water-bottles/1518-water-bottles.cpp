class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int full=numBottles;
        int empty=0;
        int ans=0;
        while(full){
            ans+=full;
            int s=full+empty;
            full=s/numExchange;
            empty=s%numExchange;
        }
        return ans;
    }
};