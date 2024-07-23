class Solution {
public:
vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
    vector<pair<int, string>> a;
    for (int i = 0; i < names.size(); ++i) {
        a.push_back( {heights[i], names[i]});
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < a.size(); ++i) {

        names[i] = a[i].second;
    }
    return names;
}
};