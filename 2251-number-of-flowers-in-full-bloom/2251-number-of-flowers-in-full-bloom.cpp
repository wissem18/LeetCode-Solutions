class Solution {
public:

vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people) {
    int n = people.size();
    vector<pair<int,int>>people_ind;
    for (int i = 0; i < n; ++i) {
        people_ind.push_back({people[i],i});
    }
    sort(people_ind.begin(), people_ind.end());
    int m=flowers.size();
    sort(flowers.begin(),flowers.end());
    vector<int>ans(n);
    priority_queue<int,vector<int>,greater<int>>pq;
    int lst=0;
    for (int i = 0; i < n; ++i) {
        vector<int>tmp={people_ind[i].first,1000000007};
        int x= upper_bound(flowers.begin(),flowers.end(),tmp)-flowers.begin();
        for (int j = lst; j < x; ++j) {
            pq.push(flowers[j][1]);
        }
      while(!pq.empty()&&pq.top()<people_ind[i].first)
          pq.pop();
      ans[people_ind[i].second]=pq.size();
      lst=x;
    }
    return ans;
}
};