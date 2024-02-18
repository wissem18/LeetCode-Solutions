class Solution {
public:
int mostBooked(int n, vector<vector<int>>& meetings) {
   priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
    for (int i = 0; i < n; ++i) {
        pq.push({0,i});
    }
   vector<int>used(n,0);
    sort(meetings.begin(),meetings.end());
    for (int i = 0; i < meetings.size(); ++i) {
        long long l=meetings[i][0];
        long long r=meetings[i][1];
        vector<pair<long long,int>>cur;
        while(!pq.empty()&&pq.top().first<=l){
            cur.push_back(pq.top());
            pq.pop();
        }
        if(cur.empty()){
            pair<long long,int>p=pq.top();
            pq.pop();
            used[p.second]++;
            pq.push({r+p.first-l,p.second});
        }
        else{
            int mn=1000;
            for (int j = 0; j < cur.size(); ++j) {
                if(cur[j].second<mn){
                    mn=cur[j].second;
                }
            }
            used[mn]++;
            pq.push({r,mn});
            for (int j = 0; j < cur.size(); ++j) {
                if(cur[j].second==mn)continue;
                pq.push(cur[j]);
            }
        }
    }
    int ans= max_element(used.begin(),used.end())-used.begin();
    return ans;
}
};