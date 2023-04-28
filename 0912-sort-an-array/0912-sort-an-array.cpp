class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int>q;
        for (int i = 0; i < nums.size(); ++i) {
            q.push(-nums[i]);
        }
        for (int i = 0; i < nums.size(); ++i) {
            nums[i]=-q.top();
            q.pop();
        }
        return nums;
    }
};