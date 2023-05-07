class Solution {
public:

vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
int n=obstacles.size();
vector<int>ans(n),lis;
    for (int i = 0; i < n; ++i) {
        int ind=upper_bound(lis.begin(),lis.end(),obstacles[i])-lis.begin();
        if(ind==lis.size()){
            lis.push_back(obstacles[i]);
            ans[i]=ind+1;
        }
        else{
            lis[ind]=obstacles[i];
            ans[i]=ind+1;
        }
    }
    return ans;
}
};