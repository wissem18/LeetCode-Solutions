class Solution {
public:
bool checkIfExist(vector<int> &arr) {
    unordered_map<int, int> occ;
    for (int i = 0; i < arr.size(); ++i) {
        occ[arr[i]]++;
    }
    for (int i = 0; i < arr.size(); ++i) {
        if (occ.count(arr[i] * 2) && arr[i] != 0)
            return true;
        if (arr[i] == 0 && occ[0] > 1)
            return true;
    }
    return false;
}
};