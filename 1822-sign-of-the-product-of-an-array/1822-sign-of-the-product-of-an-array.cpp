class Solution {
public:
 int arraySign(vector<int> &nums) {
int nb=0;
bool test=false;
    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i]==0){
            test=true;
            break;
        }
        if(nums[i]<0)
            nb++;
    }
    if(test)
        return 0;
    else{
        if(nb%2)
            return -1;
        else
            return 1;
    }
}
};