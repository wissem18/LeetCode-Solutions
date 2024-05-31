class Solution {
public:
vector<int> singleNumber(vector<int>& nums) {
int axorb=0;
    for (int i = 0; i < nums.size(); ++i) {
        axorb^=nums[i];
    }
    // in the set bit (i) of axorb a and b will have different bits 0 and 1 so we divide the array into 2 groups one with set bit (i) and one with not set bit
    //so one group will contain a and the other contains b separated so we can xor all the elements of one group to get a or b (because each group will have only one
    //number a or b which appears only once )
    int i=0;
    for (; i <32 ; ++i) {
        if(axorb&(1<<i))
            break;
    }
    int a=0;
    for (int j = 0; j < nums.size(); ++j) {
        if(nums[j]&(1<<i)){
            a^=nums[j];
        }
    }
    int b=a^axorb;
    return {a,b};
 }
};