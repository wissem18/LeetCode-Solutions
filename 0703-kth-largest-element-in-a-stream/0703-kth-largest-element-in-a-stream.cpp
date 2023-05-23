class KthLargest {
public:
    int m;
   priority_queue<int,vector<int>, greater<int>>q;
    KthLargest(int k, vector<int>& nums) {
        m=k;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
    }
    
    int add(int val) {
        q.push(val);
        while(q.size()>m){
            q.pop();
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */