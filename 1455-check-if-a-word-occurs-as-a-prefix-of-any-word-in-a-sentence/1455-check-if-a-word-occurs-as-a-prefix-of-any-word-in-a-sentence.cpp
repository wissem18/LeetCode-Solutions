class Solution {
public:
int isPrefixOfWord(string sentence, string searchWord) {
    string cur = "";
    int cnt = 1;
    for (int i = 0; i < sentence.size(); ++i) {
        if (sentence[i] == ' ') {
            if (cur.size() >= searchWord.size() && cur.substr(0, searchWord.size()) == searchWord)
                return cnt;
            cnt++;
            cur = "";
        } else
            cur += sentence[i];
    }
    if (cur.size() >= searchWord.size() && cur.substr(0, searchWord.size()) == searchWord)
        return cnt;
    
    return -1;
}
};