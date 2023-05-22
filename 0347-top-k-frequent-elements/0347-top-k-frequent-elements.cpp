class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
unordered_map<int,int>m;
    for (int i = 0; i < nums.size(); ++i) {
        m[nums[i]]++;
    }
    priority_queue<pair<int,int>>q;
    for (auto x:m) {
      q.push({x.second,x.first});
    }
    vector<int>ans;
    while(k--){
        ans.push_back(q.top().second);
        q.pop();
    }
    return ans;
}
};