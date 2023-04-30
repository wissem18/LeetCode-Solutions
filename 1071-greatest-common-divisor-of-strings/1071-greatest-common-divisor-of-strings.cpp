class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
    int n = __gcd(str1.size(), str2.size());
    string res = "";
    for (int i = 1; i <= n; ++i) {
        if (str1.size() % i == 0 && str2.size() % i == 0) {
            string k = str1.substr(0, i);
            string s1 = "", s2 = "";
            for (int j = 0; j < str1.size() / i; ++j) {
             s1+=k;
            }
            for (int j = 0; j < str2.size() / i; ++j) {
                s2+=k;
            }
            if(s1==str1&&s2==str2){
                res=k;
            }
        }
    }
    return res;
}
};