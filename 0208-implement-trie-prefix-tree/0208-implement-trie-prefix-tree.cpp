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
class Trie {
public:
    TrieNode* root;
    Trie() {
         root=new TrieNode();
    }

    void insert(string word) {
     TrieNode* tmp=root;
        for (int i = 0; i < word.size(); ++i) {
            int idx=word[i]-'a';
            if(!tmp->children[idx])
                tmp->children[idx]=new TrieNode();
            tmp=tmp->children[idx];
        }
        tmp->isEndOfWord=true;
    }

    bool search(string word) {
     TrieNode* tmp=root;
        for (int i = 0; i < word.size(); ++i) {
            int idx=word[i]-'a';
            if(!tmp->children[idx])
                return false;
            tmp=tmp->children[idx];
        }
        return tmp->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* tmp=root;
        for (int i = 0; i < prefix.size(); ++i) {
            int idx=prefix[i]-'a';
            if(!tmp->children[idx])
                return false;
            tmp=tmp->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */