class Solution {
public:
    double average(vector<int>& salary) {
    int mx=0,mn=1e9;
    int sum=0;
    for (int i = 0; i < salary.size(); ++i) {
        mx=max(mx,salary[i]);
        mn=min(mn,salary[i]);
        sum+=salary[i];
    }
    sum-=(mx+mn);
    double ans=sum*1.0/(salary.size()-2);
    return ans;
}
};