class Solution {
public:
    vector<string>ans;
map<char,char>first;
void rec(int i,string cur,string &digits){
    if(i==digits.size()){
        ans.push_back(cur);
        return ;
    }
    if(digits[i]=='7'||digits[i]=='9'){
        for (int j = 0; j < 4; ++j) {
         rec(i+1,cur+char(first[digits[i]]+j),digits);
        }
    }
    else{
        for (int j = 0; j < 3; ++j) {
            rec(i+1,cur+char(first[digits[i]]+j),digits);
        }
    }

}
vector<string> letterCombinations(string digits) {
    if(digits=="")
        return ans;
first['2']='a',first['3']='d',first['4']='g',first['5']='j',first['6']='m',first['7']='p',first['8']='t',first['9']='w';
rec(0,"",digits);
return ans;
}
};