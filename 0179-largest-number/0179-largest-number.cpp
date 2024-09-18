class Solution {
public:
string largestNumber(vector<int> &nums) {
    vector<string> s;
    for (auto x: nums) {
        s.push_back(to_string(x));
    }
    sort(s.rbegin(), s.rend(), [](string &a, string &b) {
        return a+b < b+a ;
    });
    if(s[0]=="0")
        return "0";
    string ans;
    for (auto x: s) {
        ans += x;
    }
    return ans;
}
};