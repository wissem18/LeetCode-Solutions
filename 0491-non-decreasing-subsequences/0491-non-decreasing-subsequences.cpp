class Solution {
public:
vector<vector<int>> findSubsequences(vector<int>& nums) {

    int n=nums.size();
    int x=1<<n;
    vector<vector<int>> tmp(x);
    int k=0;
    for (int i = 3; i <1<<n; ++i) {
        if((i&(i-1))==0)
            continue;
        for (int j = 0; j < n; ++j) {
            if((i&(1<<j))!=0){
                tmp[k].push_back(nums[j]);
            }
        }
        k++;
}
    set<vector<int>>res;
    for (int i = 0; i < tmp.size(); ++i) {
        bool test=true;
        if(tmp[i].empty())
            break;
        for (int j = 1; j < tmp[i].size(); ++j) {
            if(tmp[i][j-1]>tmp[i][j]){
                test=false;
                break;
            }
        }
        if(test)
            res.insert(tmp[i]);
    }
    return vector(res.begin(),res.end());
}
};