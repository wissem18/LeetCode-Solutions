class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX,maxp=0;
    for (int i = 0; i < prices.size(); ++i) {
        if(prices[i]<minprice)
            minprice=prices[i];
        else if(prices[i]-minprice>maxp)
            maxp=prices[i]-minprice;
    }
    return maxp;
    }
};