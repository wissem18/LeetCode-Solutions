class Solution {
public:
int n,m;
int mem[500][500][2];
int dp(int i,int j,int pick,vector<int>& nums1, vector<int>& nums2){
    if(i==n||j==m){
        if(pick) return 0;
        return -1e9;
    }
     if(mem[i][j][pick]!=-1)
         return mem[i][j][pick];
    return mem[i][j][pick]=max({dp(i+1,j+1,pick|1,nums1,nums2)+nums1[i]*nums2[j],dp(i+1,j,pick,nums1,nums2),dp(i,j+1,pick,nums1,nums2)});
}
int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    n=nums1.size();
    m=nums2.size();
    memset(mem,-1,sizeof mem);
    return dp(0,0,0,nums1,nums2);
}
};