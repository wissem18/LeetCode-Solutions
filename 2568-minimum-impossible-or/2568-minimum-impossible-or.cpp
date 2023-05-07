class Solution {
public:
int minImpossibleOR(vector<int>& nums) {
sort(nums.begin(),nums.end());
    for (int i = 0; i <31; ++i) {
        if(upper_bound(nums.begin(),nums.end(),(1<<i))==lower_bound(nums.begin(),nums.end(),(1<<i))){
            return (1<<i);
        }
    }
return(1<<31);
}
};