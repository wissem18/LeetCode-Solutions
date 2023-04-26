class Solution {
public:
int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
    vector<pair<int, int>> a;
    for (int i = 0; i < profits.size(); ++i) {
        a.push_back({capital[i], profits[i]});
    }
    sort(a.begin(), a.end());
    priority_queue<int>mxcapital;
    int i=0;
    while(k--){
        while(i<a.size()&&a[i].first<=w){
            mxcapital.push(a[i].second);
          i++;
        }
        if(mxcapital.empty())
            return w;
        w+=mxcapital.top();
        mxcapital.pop();
    }
    return w;
}
};