class Solution {
public:
 long long wonderfulSubstrings(string word) {
int n=word.size();
map<int,int>occ;
int cur=0;
long long ans=0;
    for (int i = 0; i <n ; ++i) {
        cur^=(1<<(word[i]-'a'));
        if((cur&(cur-1))==0)
            ans++;
        for(int j=0;j<10;j++){
            ans+=occ[cur^(1<<j)];
        }
        ans+=occ[cur];
        occ[cur]++;
    }
    return ans;
}
};