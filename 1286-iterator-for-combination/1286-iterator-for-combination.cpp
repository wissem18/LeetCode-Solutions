class CombinationIterator {
public:
    vector<string>ans;
    int cur;
    CombinationIterator(string characters, int combinationLength) {
      int n=characters.size();
        for (int i = 0; i < (1<<n); ++i) {
            if(__builtin_popcount(i)==combinationLength){
                string cur;
                for (int j = 0; j < n; ++j) {
                    if(i&(1<<j))
                        cur.push_back(characters[j]);
                }
                ans.push_back(cur);
            }
        }
        sort(ans.begin(),ans.end());
        cur=0;
    }

    string next() {
       return ans[cur++];
    }

    bool hasNext() {
     return(cur<ans.size());
         
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */