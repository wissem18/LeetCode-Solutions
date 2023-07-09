class Solution {
public:
int largestVariance(string s) {
    int n=s.size();
    int ans=0;
    vector<int>occ(26,0);
    for (int i = 0; i < n; ++i) {
        occ[s[i]-'a']++;
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j <26 ; ++j) {
            if(i==j||!occ[i]||!occ[j])
                continue;
            int sum=0,cnt1=0,cnt2=0;
            int r=occ[j];
            for (int k = 0; k <n ; ++k) {
                if(s[k]-'a'==i){
                    cnt1++;
                }
                if(s[k]-'a'==j){
                    cnt2++;
                   r--;
                }
                if(cnt2>0){
                    ans=max(ans,cnt1-cnt2);
                }
              if(cnt1<cnt2&&r>0){
                  cnt1=cnt2=0;
              }
            }
        }
    }
    return ans;
}
};