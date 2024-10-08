class Solution {
public:
int minSwaps(string s) {
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '[') {
            cnt++;
        }
        if (s[i] == ']') {
            if (cnt)
                cnt--;
        }
    }
    int ans = (cnt + 1) / 2;
    return ans;
}
};