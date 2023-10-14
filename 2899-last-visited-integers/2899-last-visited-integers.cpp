class Solution {
public:
  vector<int> lastVisitedIntegers(vector<string> &words) {
    vector<int> ans;
    vector<int> cur;
    for (int i = 0; i < words.size();) {
        if (words[i] == "prev") {
            int x = cur.size() - 1;
            while (i < words.size() && words[i] == "prev") {
                if (x < 0)
                    ans.push_back(-1);
                else
                    ans.push_back(cur[x]);
                x--;
                i++;
            }

        } else {
            cur.push_back(stoi(words[i]));
            i++;
        }
    }
    return ans;
}
};