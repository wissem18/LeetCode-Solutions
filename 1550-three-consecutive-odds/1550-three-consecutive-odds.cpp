class Solution {
public:
bool threeConsecutiveOdds(vector<int>& arr) {
    int n=arr.size();
    for (int i = 0; i <n-2 ; ++i) {
        int cnt=0;
        for (int j = i; j <i+3 ; ++j) {
            cnt+=arr[j]%2;
        }
        if(cnt>2)
            return true;
    }
    return false;
}
};