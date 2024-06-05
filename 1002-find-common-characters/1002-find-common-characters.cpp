class Solution {
public:
vector<string> commonChars(vector<string> &words) {
vector<string>ans;
    for (char c = 'a'; c <= 'z'; c++) {
        int x = 1000;
        for (int i = 0; i < words.size(); ++i) {
            int a= count(words[i].begin(), words[i].end(),c);
            x=min(x,a);
        }

        for (int i = 0; i < x; ++i) {
            string s="";
            s+=c;    
            ans.push_back(s);
        }
    }
    return ans;
}
};