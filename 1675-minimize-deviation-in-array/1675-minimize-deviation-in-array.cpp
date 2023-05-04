class Solution {
public:
int minimumDeviation(vector<int>& nums) {
    priority_queue<int>qu;
    int mn=INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i]%2)
            nums[i]*=2;
        qu.push(nums[i]);
        mn=min(nums[i],mn);
    }
    int ans=INT_MAX;
    while(qu.top()%2==0){
        ans=min(ans,qu.top()-mn);
        mn=min(mn,qu.top()/2);
        qu.push(qu.top()/2);
        qu.pop();

    }
    ans=min(ans,qu.top()-mn);
    return ans;
}
};