# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
the first intuition is the collision problem in fact it's not a problem is just when two robots collide will start to move in opposite directions but since at the beginning nums[i] is unique so two robots can collide if and only if they are moving oppositly from the beginning . So the problem will becom easy just add or substract d from each robot position and compute the differences.

second intuition is about how to compute differences (the positive ones because the problem said the absolute difference).
let for example an array [a0,a1,a2] sorted in decreasing order what will be the sum of positive differences of all pairs 

S=(a0-a1)+(a0-a1)+(a1-a2). 
a1: added 2 times and substracted 0 times
a2: added 1 times and substracted 1 times
a3: added 0 times and substracted 2 times
So in general we can say that each element ai will be added n-i-1 times and substracted i times in the total sum of differences so the contribution of each element ai in the total sum will be n-2*i-1.

last intuition don't forget the modulo and mostly the negative case 
(A-B)%MOD=(A%MOD+(-B)%MOD+MOD)%MOD  
# Approach
<!-- Describe your approach to solving the problem. -->
As described above we will firstly begin by looping for all the robots positions and add d if its direction is R or substract d if its direction is L.
Now we have the final positions of each robot after d seconds, So the rest of the problem is to compute the sum of differences : 
First sort the array nums in decreasing order then compute the contribution of each element to the total sum . 
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
 O(NlogN)
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
O(N)
# Code
```
class Solution {
public:
int MOD=1000000007;
int sumDistance(vector<int>& nums, string s, int d) {
int n=nums.size();
    for (int i = 0; i < n; ++i) {
        if(s[i]=='R'){
          nums[i]=nums[i]+d;
        }
        else{
            nums[i]=nums[i]-d;
        }
    }
    sort(nums.rbegin(),nums.rend());
    int ans=0;
    for (int i = 0; i < n; ++i) {
        ans=(ans%MOD+(nums[i]*1LL*(n-2*i-1))%MOD+MOD)%MOD;
    }
    
    return ans;
}
};
```
