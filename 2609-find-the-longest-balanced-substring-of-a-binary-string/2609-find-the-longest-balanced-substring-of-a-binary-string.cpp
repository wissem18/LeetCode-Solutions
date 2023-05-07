class Solution {
public:
int findTheLongestBalancedSubstring(string s) {
    int z=0,o=0;
    int ans=0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]=='0'){
            if(i-1>=0&&s[i-1]=='1'){
                o=0;
                z=0;
            }
            z++;
        }
        else{
            o++;
            ans=max(min(o,z)*2,ans);
        }
    }
    return ans;
}
};