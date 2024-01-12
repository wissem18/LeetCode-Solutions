class Solution {
public:
bool halvesAreAlike(string s) {
string v="aeuioAEUIO";
int cnt=0;
    for (int i = 0; i < s.size(); ++i) {
        if(v.find(s[i])!=string::npos){
            cnt+=(i<s.size()/2)?1:-1;
        }
    }
    return cnt==0;
}
};