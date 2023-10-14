class Solution {
public:
vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
vector<string>ans0,ans1;
int x=0;
    for (int i = 0; i < n; ++i) {
        if(groups[i]==x){
            ans0.push_back(words[i]);
            x^=1;
        }
    }
x=1;
    for (int i = 0; i < n; ++i) {
        if(groups[i]==x){
            ans1.push_back(words[i]);
            x^=1;
        }
    }
    if(ans0.size()>ans1.size())
        return ans0;
    return ans1;
}
};