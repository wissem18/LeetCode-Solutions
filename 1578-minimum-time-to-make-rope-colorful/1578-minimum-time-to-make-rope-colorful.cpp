class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        if(colors.size()){
            int mx=neededTime[0];
            ans+=neededTime[0];
            for(int i=1;i<colors.size();i++){
                if(colors[i]==colors[i-1]){
                    ans+=neededTime[i];
                    mx=max(mx,neededTime[i]);
                }
                else{
                    ans-=mx;
                    ans+=neededTime[i];
                    mx=neededTime[i];
                }
            }
            ans-=mx;
        }
        return ans;
    }
};