class Solution {
public:

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
    unordered_set<int> s;
    for (auto x: arr1) {
        int b = log10(x);
        for (int i = b; i >= 0; --i) {
            int cur = x / pow(10, i);
            s.insert(cur);
        }
    }

    int ans = 0;
    for (auto x: arr2) {
        int b = log10(x);
        for (int i = b-ans; i >= 0; --i) {
            int cur = x / pow(10, i);
            if(s.count(cur)){
                ans=b-i+1;
            }
        }
    }
    return ans;
}
};