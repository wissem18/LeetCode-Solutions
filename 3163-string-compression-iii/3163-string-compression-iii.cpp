class Solution {
public:
string compressedString(string word) {
    int n = word.size();
    string ans = "";
    int i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && word[j] == word[i] && j - i < 9) j++;
        ans += '0' + j - i;
        ans += word[i];
        i = j;
    }
    return ans;
}
};