class Solution {
public:
int findKthPositive(vector<int>& arr, int k) {
    int last=0;
    for (int i = 0; i < arr.size(); ++i) {
        if(arr[i]-last-1>=k){
            return last+k;
        }
        else{
            k-=arr[i]-last-1;
            last=arr[i];
        }
    }
    return last+k;
}
};