class Solution {
public:
vector<string> removeSubfolders(vector<string> &folder) {
    set<string> s;
    int n = folder.size();
    for (auto ss: folder) {
        s.insert(ss);
    }
    vector<int> rem(n, 0);
    for (int i = 0; i < n; ++i) {
        string cur = "";
        for (int j = 0; j < folder[i].size(); ++j) {
            if (folder[i][j] == '/' && s.count(cur)) {
                rem[i] = 1;
                break;
            }
            cur += folder[i][j];
        }
    }
    vector<string> ans;
    for (int i = 0; i < n; ++i) {
        if (!rem[i])
            ans.push_back(folder[i]);
    }
    return ans;
}
};