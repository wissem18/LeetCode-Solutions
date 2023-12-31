class Solution {
public:
   int maxLengthBetweenEqualCharacters(string s) {
int ans=-1;
    for (int i = 0; i < 26; ++i) {
        int first=-1,last=-1;
        for (int j = 0; j < s.size(); ++j) {
            if(s[j]=='a'+i){
                first=j;
                break;
            }
        }
        for (int j = s.size()-1; j >=0 ; --j) {
            if(s[j]=='a'+i){
                last=j;
                break;
            }
        }
        if(first!=-1)
            ans=max(ans,last-first-1);
    }
    return ans;
}
};