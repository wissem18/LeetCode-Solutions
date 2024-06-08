class Solution {
public:
     string helper(string word, unordered_set<string> dictSet) {
        // Find the shortest root of the word in the dictionary
        for (int i = 1; i <= word.length(); i++) {
            string root = word.substr(0, i);
            if (dictSet.contains(root)) {
                return root;
            }
        }
        // There is not a corresponding root in the dictionary
        return word;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream sStream(sentence);
        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());

        // Replace each word in sentence with the corresponding shortest root
        string word;
        string ans;
        while (getline(sStream, word, ' ')) {
            ans += helper(word, dictSet) + " ";
        }

        ans.pop_back();  // remove extra space
        return ans;
    }

};