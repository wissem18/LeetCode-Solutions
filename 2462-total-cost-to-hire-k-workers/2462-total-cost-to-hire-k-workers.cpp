class Solution {
public:
long long totalCost(vector<int>& costs, int k, int candidates) {
    int n=costs.size();
    priority_queue<int>ql,qr;
    for (int i = 0; i < min(candidates,n); ++i) {
        ql.push(-costs[i]);
    }
    for (int i = n-1; i >=max(n-candidates,candidates) ; --i) {
        qr.push(-costs[i]);
    }
    long long ans=0;
    int i=candidates;
    int j=n-candidates-1;
    while(k--){
        int x=1e9;
        if(!ql.empty())
            x=-ql.top();
        int y=1e9;
        if(!qr.empty())
            y=-qr.top();
        if(x<=y){
            ans+=x;
            ql.pop();
            if(i<=j){
                ql.push(-costs[i]);
                i++;
            }

        }
        else{
            ans+=y;
            qr.pop();
            if(i<=j){
                qr.push(-costs[j]);
                j--;
            }
        }
    }
    return ans;
}
};