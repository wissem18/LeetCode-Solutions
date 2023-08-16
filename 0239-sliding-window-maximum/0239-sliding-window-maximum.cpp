class Solution {
public:
    int n;
//the array that we store the queries answers
vector<vector<int>>lookup;
void buildSparseTable(vector<int> arr)
{
// Initialize M for the intervals with length 1
    for (int i = 0; i < n; i++)
        lookup[i][0] = arr[i];
// Compute values from smaller to bigger intervals
    for (int j = 1; (1 << j) <= n; j++) {
// Compute maximum value for all intervals with size 2^j
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            lookup[i][j]=max(lookup[i][j - 1],lookup[i + (1 << (j - 1))][j - 1]);
        }
    }
}
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
n=nums.size();
lookup.assign(n,vector<int>(log2(n)+1));
    buildSparseTable(nums);
vector<int>ans;
    int j=(int)log2(k);
    for (int i = 0; i <= n-k; ++i) {
        ans.push_back(max(lookup[i][j],lookup[i+k-(1<<j)][j]));
    }
    return ans;
}
};