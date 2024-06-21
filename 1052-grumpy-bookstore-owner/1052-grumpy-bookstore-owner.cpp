class Solution {
public:
int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
    int n = customers.size();
    int ans=0;
    for (int i = 0; i < n; ++i) {
        if(!grumpy[i])
            ans+=customers[i];
    }
    int cur=0;
    for (int i = 0; i < minutes; ++i) {
        if(grumpy[i])
            cur+=customers[i];
    }
    int maxProfit=cur;
    for (int i = minutes; i <n ; ++i) {
        if(grumpy[i])
            cur+=customers[i];
        if(grumpy[i-minutes])
            cur-=customers[i-minutes];
        maxProfit=max(maxProfit,cur);
    }
    return ans+maxProfit;
}
};