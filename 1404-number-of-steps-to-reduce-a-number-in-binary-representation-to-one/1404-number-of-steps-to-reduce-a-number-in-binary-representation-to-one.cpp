class Solution {
public:
int numSteps(string s) {
    int ans = 0;
    int carry = 0;
    for (int i = s.size() - 1; i > 0; --i) {
        if (carry) {
            ans++;
            if(s[i]=='0'){
                ans+=1;
            }
        } else {
            ans += 1;
            if (s[i] == '1') {
                ans += 1;
                carry = 1;
            }
        }
    }
    if(carry)
        ans+=1;
    return ans;
}
};