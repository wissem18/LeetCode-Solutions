class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        multiset<int>s1(arr.begin(),arr.end()),s2(target.begin(),target.end());
        return s1==s2;
    }
};