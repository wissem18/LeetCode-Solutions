class Solution {
public:
int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    map<int, int> occ;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        occ[arr[i]]++;
    }
    vector<int>a;
    for (auto x:occ) {
        a.push_back(x.second);
    }
    sort(a.begin(),a.end());
    int sum=0;
    int cnt=0;
    for (int i = 0; i < a.size(); ++i) {
        if(sum+a[i]>k)
            break;
        sum+=a[i];
        cnt++;
    }
    return a.size()-cnt;
}
};