class Solution {
public:
int findMaxK(vector<int>& nums) {
vector<int>occ(2001,0);
    for (int i = 0; i < nums.size(); ++i) {
        occ[nums[i]+1000]++;
    }
    for (int i = 2000; i >=1000 ; --i) {
        if(occ[i]>0&&occ[2000-i]>0)
            return i-1000;
    }
    return -1;
}
};