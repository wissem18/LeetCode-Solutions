class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>m;
        for(auto c:s ){
            m[c]++;
        }
        int ans=0;
        for(auto x:m){
            ans+=x.second-x.second%2;
        }
        for(auto x:m){
            if(x.second%2){
                ans++;
                break;
            }
        }
        return ans;
    }
};