class Solution {
public:
int minLengthAfterRemovals(vector<int>& nums) {
    int n=nums.size();
   map<int,int>occ;
    for (int i = 0; i < n; ++i) {
        occ[nums[i]]++;
    }
    int mx=0;
    for (auto x:occ) {
        mx=max(mx,x.second);
    }
    if(n%2==0){
       if(mx>n/2)
           return 2*mx-n;
       else
           return 0;
    }
    else {
        mx--;
        n--;
        if(mx>n/2)
            return 2*mx-n+1;
        else
            return 1;
    }
}
};