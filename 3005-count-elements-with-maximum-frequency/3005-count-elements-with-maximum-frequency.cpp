class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>occ(101,0);
        for(int i=0;i<nums.size();i++){
            occ[nums[i]]++;
        }
        int mx=*max_element(occ.begin(),occ.end());
        int ans=0;
        for(auto x:occ){
            if(x==mx)
                ans+=mx;
        }
        return ans;
    }
};