class Solution {
public:
vector<string> buildArray(vector<int> &target, int n) {
    int i = 1;
    vector<string> ans;
    for (int j = 0; j < target.size(); ++j) {
        if (i != target[j]) {
            while (i != target[j])
                ans.emplace_back("Push"), ans.emplace_back("Pop"), i++;
        }
        ans.emplace_back("Push");
        i++;
    }
    return ans;
}
};