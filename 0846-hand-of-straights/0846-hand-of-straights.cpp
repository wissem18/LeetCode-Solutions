class Solution {
public:
bool isNStraightHand(vector<int> &hand, int groupSize) {
    int n = hand.size();
    if (n % groupSize)
        return false;
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
        m[hand[i]]++;
    }
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<>> q;
    for (auto x: m) {
        q.push(x);
    }
    while (!q.empty()) {
        int x = groupSize;
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