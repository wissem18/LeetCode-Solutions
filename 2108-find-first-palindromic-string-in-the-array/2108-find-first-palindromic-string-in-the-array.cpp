class Solution {
public:
bool isPalindrome(string s){
    for (int i = 0; i < s.size()/2; ++i) {
        if(s[i]!=s[s.size()-i-1])
            return false;
    }
    return true;
}
string firstPalindrome(vector<string>& words) {
string ans="";
    for (int i = 0; i < words.size(); ++i) {
        if(isPalindrome(words[i])){
            ans=words[i];
            break;
        }
    }
    return ans;
}
};