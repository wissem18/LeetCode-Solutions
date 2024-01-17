class Solution {
public:
bool uniqueOccurrences(vector<int>& arr) {
map<int,int>occ;
    for (int i = 0; i < arr.size(); ++i) {
        occ[arr[i]]++;
    }
    set<int>s;
    for (auto x:occ) {
       if(s.count(x.second))
           return false;
       s.insert(x.second);
    }
    return true;
}
};