class Solution {
public:
    bool isVowel(char c){
    string s="aeuio";
    if(s.find(c)!=string::npos)
        return true;
        return false;
}
vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
vector<int>pre(words.size()+1,0);
    for (int i = 0; i <words.size(); ++i) {
        pre[i+1]=pre[i]+(isVowel(words[i][0])&&isVowel(words[i][words[i].size()-1]));
    }
    vector<int>res;
    for (int i = 0; i < queries.size(); ++i) {
      res.push_back(pre[queries[i][1]+1]-pre[queries[i][0]]);
    }
    return res;
}
};