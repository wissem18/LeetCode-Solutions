class Solution {
public:
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
int n=heights.size();
priority_queue<int,vector<int>,greater<>>q;
    int i=1;
    for (; i < n; ++i) {
        if(heights[i]-heights[i-1]>0&&ladders){
           q.push(heights[i]-heights[i-1]);
           ladders--;
        }
        else if (heights[i]-heights[i-1]>0){
            q.push(heights[i]-heights[i-1]);
            bricks-=q.top();
            q.pop();
        }
        if(bricks<0){
            break;
        }
    }
return i-1;
}
};