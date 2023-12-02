class Solution {
public:

int countCharacters(vector<string>& words, string chars) {
vector<int>occ(26,0);
    for (int i = 0; i < chars.size(); ++i) {
        occ[chars[i]-'a']++;
    }
    int ans=0;
    vector<int>cur(26,0);
    for (int i = 0; i < words.size(); ++i) {
         cur.assign(26,0); 
        for (int j = 0; j < words[i].size(); ++j) {
            cur[words[i][j]-'a']++;
        }
        bool test=true;
        for (int j = 0; j < 26; ++j) {
            if(cur[j]>occ[j]){
                test=false;
                break;
            }
        }
        if(test)ans+=words[i].size();
    }
    return ans;
}
};