class Solution {
public:
int partitionString(string s) {
vector<bool>vis(26,false);
int ans=1;
    for (int i = 0; i < s.size(); ++i) {
        if(vis[s[i]-'a']){
            ans++;
            vis.assign(26, false);
            vis[s[i]-'a']=true;
        }
        else
            vis[s[i]-'a']=true;
    }
    return ans;
}
};