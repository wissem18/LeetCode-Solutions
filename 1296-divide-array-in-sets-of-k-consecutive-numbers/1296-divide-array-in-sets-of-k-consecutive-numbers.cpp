class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
      int n = nums.size();
    if (n % k)
        return false;
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
        m[nums[i]]++;
    }
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<>> q;
    for (auto x: m) {
        q.push(x);
    }
    while (!q.empty()) {
        int x = k;
        vector<pair<int,int>>a;
        pair<int,int>cur=q.top();
        q.pop();
        if(cur.second-1){
            a.push_back({cur.first,cur.second-1});
        }
        x--;
        while(x--&&cur.first==q.top().first-1){
            cur=q.top();
            q.pop();
            if(cur.second-1){
                a.push_back({cur.first,cur.second-1});
            }
        }
        if(x>=0)
            return false;
        for (auto e:a) {
            q.push(e);
        }
    }
    return true;
    }
};