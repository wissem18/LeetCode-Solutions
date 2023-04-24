struct TrieNode{
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode(){
        for (int i = 0; i < 26; ++i) {
            children[i]=NULL;
            isEndOfWord=false;
        }
    }
};
class WordDictionary {
public:
 TrieNode* node;
    WordDictionary() {
         node=new TrieNode();
    }
    
    void addWord(string word) {
      TrieNode* tmp=node;
        for (int i = 0; i < word.size(); ++i) {
            int idx=word[i]-'a';
            if(!tmp->children[idx])
                tmp->children[idx]=new TrieNode();
            tmp=tmp->children[idx];
        }
        tmp->isEndOfWord=true;
    }
    
    bool search(string word) {
     return search_helper(word,node);
    }
private:
bool search_helper(string word,TrieNode* root){
        for (int i = 0; i < word.size(); ++i) {
            if(word[i]=='.')
           {
            bool test=false;
            for(int j=0;j<26;j++){
                if(root->children[j]){
                    test|=search_helper(word.substr(i+1),root->children[j]);
                    if(test)
                    return true;
                }
            }
            return false;     
           }
           else{
            int idx=word[i]-'a';
            if(!root->children[idx])
                return false;
            root=root->children[idx];
           }
        }
        return root->isEndOfWord;
}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */