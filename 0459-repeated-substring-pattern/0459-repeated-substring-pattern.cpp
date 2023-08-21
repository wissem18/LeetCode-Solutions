class Solution {
public:
    bool repeatedSubstringPattern(string s) {
int n=s.size();
    for (int i = 1; i <n ; ++i) {
        if(n%i==0){
        string cur="";
        for (int j = 0; j <n/i ; ++j) {
            cur+=s.substr(0,i);
        }
        if(cur==s)
            return true;
        }
    }
    return false;
}
};