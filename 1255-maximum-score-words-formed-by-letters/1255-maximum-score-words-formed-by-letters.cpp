class Solution {
public:
int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
    int n = words.size();
    int ans = 0;
    unordered_map<int,int>letters_occ;
    for(auto c:letters)
        letters_occ[c-'a']++;
    for (int mask = 0; mask < (1 << n); mask++) {
        unordered_map<int,int>occ;
        for (int i = 0; i < n; ++i) {
            if(mask&(1<<i)){
              for(auto c:words[i])
                  occ[c-'a']++;
            }
        }
        //verify that you can make this subset of words by given letters 
        bool test=true;
        for (int j = 0; j < 26; ++j) {
            if(occ[j]>letters_occ[j]){
                test=false;
                break;
            }
        }
        //if it can be made so we calculate the score of the subset 
        if(test){
            int cur_ans=0;
            for (auto &[x,y]:occ) {
                cur_ans+=y*score[x];
            }
            ans=max(ans,cur_ans);
        }
        
    }
    return ans;

}
};