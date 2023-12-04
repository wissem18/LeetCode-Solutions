class Solution {
public:
    string largestGoodInteger(string num) {
    int n = num.size();
    set<string> s;
    for (int i = 0; i < n - 2; ++i) {
        if(num[i]==num[i+1]&&num[i+1]==num[i+2]){
            string cur=num.substr(i,3);
            s.insert(cur);
        } 
    }
 if(s.empty())
     return "";
return *s.rbegin();    
}
};