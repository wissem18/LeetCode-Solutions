class Solution {
public:
  double averageWaitingTime(vector<vector<int>> &customers) {
    long long ans = customers[0][1];
    int cur = customers[0][0] + customers[0][1];
    for (int i = 1; i < customers.size(); ++i) {
        ans += customers[i][1];
        if (cur>customers[i][0])
            ans+=(cur-customers[i][0]);
        cur=max(cur,customers[i][0])+customers[i][1];
    }
    return ans*1.0/customers.size();
}
};