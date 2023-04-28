class Solution {
public:
int totalFruit(vector<int>&fruits){
        int l=0,r=0;
        int n=fruits.size();
        vector<int>occ(n,0);
        int cnt=0;
        int ans=0;
        while(r<fruits.size()){
           if(!occ[fruits[r]])
               cnt++;
           occ[fruits[r]]++;
            while(cnt>2){
               occ[fruits[l]]--;
               if(!occ[fruits[l]])
                   cnt--;
               l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};