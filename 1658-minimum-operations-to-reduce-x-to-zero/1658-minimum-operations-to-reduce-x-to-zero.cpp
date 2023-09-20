class Solution {
public:
   int minOperations(vector<int>& nums, int x) {
int sum=0;
int n=nums.size();
    for (int i = 0; i < n; ++i) {
        sum+=nums[i];
    }
      if(sum<x)
          return -1;
    int i = 0, j = 0, cursum = 0;
    int maxLen = INT_MIN;

    while (j < n) {
        cursum += nums[j];  
        if (cursum ==sum-x) {
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        else if (cursum<sum-x ) { 
            j++;
        }
        else if (cursum>sum-x) {  
            while (cursum>sum-x) {
                cursum -= nums[i];
                i++;
            }
            if(cursum==sum-x){
                maxLen = max(maxLen, j-i+1);
            }
            j++;
        }
    }
    if(maxLen==INT_MIN)
        return -1;
    return n-maxLen;
}
};