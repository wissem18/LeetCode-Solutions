class Solution {
public:
int maxConsecutiveAnswers(string answerKey, int k) {
int n=answerKey.size();
int t=0,f=0;
int l=0,r=0;
int ans=0;
while(r<n){
    (answerKey[r]=='T')?t++:f++;
    if(min(t,f)<=k){
        r++;
    }
    else{
        (answerKey[l]=='T')?t--:f--;
        l++;
        r++;
    }
    ans=max(ans,r-l);
}
ans=max(ans,r-l);
return ans;
}
};