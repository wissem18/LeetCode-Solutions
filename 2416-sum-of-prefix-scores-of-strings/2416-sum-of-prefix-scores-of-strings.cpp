class Solution {
public:
struct TrieNode {

    // Array for child nodes of each node
    TrieNode *child[26];

    // for the occ of prefixes
    int occ;

    TrieNode() {
        occ = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

// Method to insert a key into the Trie
void insertKey(TrieNode *root, const string &key) {

    // Initialize the curr pointer with the root node
    TrieNode *curr = root;

    // Iterate across the length of the string
    for (char c: key) {

        // Check if the node exists for the
        // current character in the Trie
        if (curr->child[c - 'a'] == nullptr) {

            // If node for current character does
            // not exist then make a new node
            TrieNode *newNode = new TrieNode();

            // Keep the reference for the newly
            // created node
            curr->child[c - 'a'] = newNode;
        }

        // Move the curr pointer to the
        // newly created node
        curr = curr->child[c - 'a'];
        curr->occ += 1;
    }

}

// Method to search a key in the Trie
int countKey(TrieNode *root, const string &key) {

    // Initialize the curr pointer with the root node
    TrieNode *curr = root;
    int ans = 0;
    // Iterate across the length of the string
    for (char c: key) {

        // Check if the node exists for the
        // current character in the Trie
        if (curr->child[c - 'a'] == nullptr)
            return 0;

        // Move the curr pointer to the
        // already existing node for the
        // current character
        curr = curr->child[c - 'a'];
        ans += curr->occ;
    }
    return ans;
}

vector<int> sumPrefixScores(vector<string> &words) {
    TrieNode *root = new TrieNode();
    for (auto word: words) {
        insertKey(root, word);
    }

    vector<int> ans(words.size());
    for (int j = 0; j < words.size(); j++) {
        ans[j] = countKey(root, words[j]);
    }
    return ans;
}
};