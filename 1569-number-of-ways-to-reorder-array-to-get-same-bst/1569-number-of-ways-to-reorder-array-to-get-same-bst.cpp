class Solution {
public:
    vector<vector<int>>C;
    int MOD=1e9+7;
    void preprocess(int &n){
        C.assign(n+1,vector<int>(n+1));
        C[1][1]=1;
        C[1][0]=1;
        for(int i=2;i<=n;i++){
            C[i][0]=1;
          for(int j=1;j<=i;j++){
              C[i][j]=(C[i-1][j]%MOD+C[i-1][j-1]%MOD)%MOD;
          }  
        }
    }
    int rec(vector<int>&nums){
         if(nums.size()<=2)
            return 1;
        vector<int>left,right;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[0])
            left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
    return (C[nums.size()-1][left.size()]*1LL*rec(left)%MOD*1LL*rec(right)%MOD)%MOD;
       
    }
    int numOfWays(vector<int>& nums) {
       int n=nums.size();
        preprocess(n);
        return (rec(nums)-1)%MOD;
    }
};