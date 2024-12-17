class Solution {
public:
string repeatLimitedString(string s, int repeatLimit) {
    priority_queue<pair<char, int>> pq;
    unordered_map<char, int> m;
    for (auto c: s) {
        m[c]++;
    }

    for (auto &[c, cnt]: m) {
        pq.push({c, cnt});
    }

    int cnt = 0;
    string ans = "";
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        if (ans != "" && ans.back() == t.first && cnt == repeatLimit) {
            if (pq.empty())
                break;
            auto st = pq.top();
            pq.pop();
            ans += st.first;
            cnt = 0;
            if (st.second > 1)
                pq.push({st.first, st.second - 1});
            pq.push(t);
        } else {
            ans += t.first;
            cnt++;
            if (t.second > 1)
                pq.push({t.first, t.second - 1});
            else
                cnt = 0;
        }

    }
    return ans;

}
};