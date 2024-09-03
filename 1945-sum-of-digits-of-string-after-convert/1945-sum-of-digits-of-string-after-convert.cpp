class Solution {
public:
int transform(int x) {
    int ans = 0;
    string s = to_string(x);
    for (int i = 0; i < s.size(); ++i) {
        ans += s[i] - '0';
    }
    return ans;
}

int getLucky(string s, int k) {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        ans += transform(s[i] - 'a' + 1);
    }
    k--;
    while (k--) {
        ans = transform(ans);
    }
    return ans;
}
};