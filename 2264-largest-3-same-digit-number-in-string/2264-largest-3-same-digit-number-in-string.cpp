class Solution {
public:
string largestGoodInteger(string num) {
    int n = num.size();
   string ans="";
    for (int i = 0; i < n - 2; ++i) {
        if(num[i]==num[i+1]&&num[i+1]==num[i+2]){
            string cur=num.substr(i,3);
            if(num[i]>ans[0])
                ans=cur;
        }
    }
return ans;
}
};