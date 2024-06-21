class Solution {
public:
int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
    int n = customers.size();
    int ans=0;
    int cur=0;
    for (int i = 0; i < minutes; ++i) {
        if(grumpy[i])
            cur+=customers[i];
        if(!grumpy[i])
            ans+=customers[i];
    }
    int maxProfit=cur;
    for (int i = minutes; i <n ; ++i) {
        if(grumpy[i])
            cur+=customers[i];
        if(grumpy[i-minutes])
            cur-=customers[i-minutes];
        maxProfit=max(maxProfit,cur);
        if(!grumpy[i])
            ans+=customers[i];
    }
    return ans+maxProfit;
}
};