class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(),s.rend());
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                swap(s[s.size()-1],s[i-1]);
                break;
            }
        }
        return s;
    }
};