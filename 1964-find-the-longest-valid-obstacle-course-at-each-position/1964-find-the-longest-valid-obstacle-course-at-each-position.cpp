class Solution {
public:
 vector<int> Tree;//the Binary indexed tree
int n;
//updating a value in the array
void update(int index,int value){
    for(;index<=n;index+=(index)&(-index))
        Tree[index]=max(value,Tree[index]);
}

//return the sum of the range [1,index]
int getPrefix(int index){
    int res=0;
    for(;index;index-=(index)&(-index))
        res=max(res,Tree[index]);
    return res;
}
vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
n=1e7+5;
Tree.resize(n);
vector<int>ans;
    for (int i = 0; i < obstacles.size(); ++i) {
     int cur= getPrefix(obstacles[i]);
     ans.push_back(cur+1);
        update(obstacles[i],cur+1);
    }
    return ans;
}
};