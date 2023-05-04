class Solution {
public:
string mergeAlternately(string word1, string word2) {
    string res="";
    int n=word1.size();
    int m=word2.size();
    for (int i = 0; i < min(n,m); ++i) {
        res+=word1[i];
        res+=word2[i];
    }
    if(n>m){
        for (int i = m; i <n ; ++i) {
            res+=word1[i];
        }
    }

    else{
        for (int i = n; i < m; ++i) {
            res+=word2[i];
        }
    }
    return res;
}
};