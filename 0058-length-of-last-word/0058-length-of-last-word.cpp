class Solution {
public:
    int lengthOfLastWord(string s) {
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' ')continue;
            else{
                int ans=0;
                while(i>=0&&s[i]!=' ')i--,ans++;
                return ans;
            }
        }
        return 0;
    }
};