class Solution {
public:
long long minimumSteps(string s) {
    long long sumpos = 0;
    long long cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            sumpos += (i + 1);
            cnt++;
        }
    }
    long long ans = sumpos - (cnt * (cnt + 1) / 2);
    return ans;
}
};