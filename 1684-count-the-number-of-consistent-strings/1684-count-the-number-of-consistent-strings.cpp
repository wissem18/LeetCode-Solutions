class Solution {
public:
int countConsistentStrings(string allowed, vector<string> &words) {
    int ans = 0;
    vector<int> occ(26, 0);
    for (int i = 0; i < allowed.size(); ++i) {
        occ[allowed[i] - 'a'] = max(1, occ[allowed[i] - 'a'] + 1);
    }
    for (int i = 0; i < words.size(); ++i) {
        bool check=true;
        for (auto c: words[i]) {
            if(!occ[c-'a']){
                check=false;
                break;
            }
        }
        if (check)
            ans++;
    }
    return ans;
}
};