class Solution {
public:
    vector<vector<int>>ans;
    void rec(int l,int n,vector<int>&a){
        if(l==n)
            ans.push_back(a);
        for(int i=l;i<=n;i++){
            swap(a[i],a[l]);
            rec(l+1,n,a);
            swap(a[i],a[l]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        rec(0,n-1,nums);
        return ans;
    }
};