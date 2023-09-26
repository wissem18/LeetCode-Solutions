class Solution {
public:
string removeDuplicateLetters(string s) {
int n=s.length();
vector<int>last_pos(26);
stack<char>st;
vector<bool>vis(26,false);
    for (int i = 0; i < n; ++i) {
        last_pos[s[i]-'a']=i;
    }
    for (int i = 0; i < n; ++i) {
        if(!vis[s[i]-'a']){
            while(!st.empty()&&st.top()>s[i]&&last_pos[st.top()-'a']>i){
                vis[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-'a']=true;
        }
    }
    string ans="";
    while(!st.empty()){
        ans=st.top()+ans;
        st.pop();
    }
    return ans;
}
};