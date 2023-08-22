class Solution {
public:
    string convertToTitle(int columnNumber) {
    string ans = "";
    int n = columnNumber;
    while (n != 0) {
        n--;
        ans = char('A' + n % 26) + ans;
        n /= 26;
    }
    return ans;
}
};