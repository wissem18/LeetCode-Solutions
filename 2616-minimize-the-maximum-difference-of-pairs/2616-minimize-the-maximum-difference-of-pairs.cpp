class Solution {
public:
bool verify(int x, int p, vector<int> &nums) {
    int cnt=0;
    for (int i = 0; i < nums.size()-1; ++i) {
        if(nums[i+1]-nums[i]<=x){
            cnt++;
            i++;
        }
    }
    return(cnt>=p);
}

int minimizeMax(vector<int> &nums, int p) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int l=0,r=1e9;
    while(l<r){
        int mid=(l+r)/2;
        if(verify(mid,p,nums))
            r=mid;
        else
            l=mid+1;
    }
    return l;
}

};