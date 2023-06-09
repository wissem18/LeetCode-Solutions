class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int x=upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        if(x==letters.size())
            x=0;
        return letters[x];
    }
};