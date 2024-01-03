class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
     int ans=0;
     int x1=0,x2=0;
        for (int i = 0; i < bank.size(); ++i) {
            if(!x1){
                for (int j = 0; j < bank[i].size(); ++j) {
                    if(bank[i][j]=='1')x1++;
                }
            }
            else if(!x2){
                for (int j = 0; j < bank[i].size(); ++j) {
                    if(bank[i][j]=='1')x2++;
                }
            }
              if(x1&&x2){
                ans+=x1*x2;
                x1=x2;
                x2=0;
              }
        }
    
     return ans;
    }
};