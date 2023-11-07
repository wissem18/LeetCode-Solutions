class Solution {
public:

int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
    int n = dist.size();
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = (dist[i]+speed[i]-1) / speed[i];
    }
    sort(arr.begin(), arr.end());
    int ans=0;
    int t=0;
    for (int i = 0; i < n; ++i) {
        if(arr[i]<=t)
            break;
        ans++;
        t++;
    }
    return ans;
}
};