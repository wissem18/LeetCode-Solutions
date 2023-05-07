class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
vector<int>res;
    long long x=0;
    for (int i = 0; i < word.size(); ++i) {
        x=x*10+(word[i]-'0');
        x%=m;
        if(x==0)
            res.push_back(1);
        else
            res.push_back(0);
    }
    return res;
}
};