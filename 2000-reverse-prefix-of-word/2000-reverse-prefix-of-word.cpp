class Solution {
public:
string reversePrefix(string word, char ch) {
int ind=word.find(ch);
if(ind==string::npos)
    return word;
    reverse(word.begin(),word.begin()+ind+1);
    return word;
}
};