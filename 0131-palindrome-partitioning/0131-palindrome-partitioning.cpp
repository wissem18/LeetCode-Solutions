class Solution {
public:
  bool isPalindrome(string s){
    string k=s;
    reverse(s.begin(),s.end());
    return(k==s);
}
vector<vector<string>> partition(string s) {
int n=s.size();
vector<vector<string>>res(1<<(n-1));
    for (int i = 0; i < (1<<(n-1)); ++i) {
        string a="";
        a+=s[0];
        for (int j = 1; j <n ; ++j) {
            if((1<<(j-1))&i){
                res[i].push_back(a);
                a="";
                a+=s[j];
            }
            else{
                a+=s[j];
            }
        }
        res[i].push_back(a);
    }
    vector<vector<string>>ans;
    for (int i = 0; i < res.size(); ++i) {
        bool test=true;
        for (int j = 0; j < res[i].size(); ++j) {
            if(!isPalindrome(res[i][j])){
                test=false;
                break;
            }
        }
        if(test)
            ans.push_back(res[i]);
    }
    return ans;
}
};