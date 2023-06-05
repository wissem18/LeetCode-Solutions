# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
how to check if 3 points are collinear
# Approach
<!-- Describe your approach to solving the problem. -->
to check if 3 points (p0,p1,p2) are collinear the slope((yi+1-yi)/(xi+1-xi)) of the two lines between p0 and p1 and between p1 and p2 must be equal. 
So we check for every 3 points if they are not collinear we return false if all the points are collinear we return true 
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
O(N)
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
O(1)
# Code
```
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
int n=coordinates.size();
    for (int i = 1; i < n-1; ++i) {
        if((coordinates[i+1][1]-coordinates[i][1])*(coordinates[i][0]-coordinates[i-1][0])!=(coordinates[i][1]-coordinates[i-1][1])*(coordinates[i+1][0]-coordinates[i][0]))
            return false;
    }
    return true;
}
};
```
