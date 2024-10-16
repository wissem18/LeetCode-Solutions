class Solution {
public:
string longestDiverseString(int a, int b, int c) {
    priority_queue<pair<int, char>> pq;
    if (a > 0) {
        pq.push({a, 'a'});
    }

    if (b > 0) {
        pq.push({b, 'b'});
    }

    if (c > 0) {
        pq.push({c, 'c'});
    }

    string ans = "";
    while (!pq.empty()) {
        pair<int, char> p = pq.top();
        pq.pop();
        int cnt = p.first;
        if (ans.length() >= 2 && ans[ans.length() - 1] == p.second &&
            ans[ans.length() - 2] == p.second) {
            if (pq.empty()) break;

            pair<int, char> temp = pq.top();
            pq.pop();
            ans += temp.second;
            if (temp.first - 1 > 0) {
                pq.push({temp.first - 1, temp.second});
            }
        } else {
            cnt--;
            ans = ans + p.second;
        }

        if (cnt > 0) {
            pq.push({cnt, p.second});
        }
    }
    return ans;
}
};