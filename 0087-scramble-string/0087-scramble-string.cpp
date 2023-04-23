class Solution {
public:
map<vector<int>,bool>mem;
bool helper(string &s1,string &s2,int st1,int end1,int st2,int end2){
    int l=end1-st1;
    if(!l){
        return(s1[st1]==s2[st2]);
    }
    if(mem.count({st1,end1,st2,end2}))
        return mem[{st1,end1,st2,end2}];
   vector<int>s1l(26,0),s1r(26,0),s2l(26,0),s2r(26,0),s22l(26,0),s22r(26,0);
    for (int i = st1; i <=end1 ; ++i) {
        s1r[s1[i]-'a']++;
    }
    for (int i = st2; i <=end2 ; ++i) {
        s2r[s2[i]-'a']++;
    }
    s22l=s2r;
    bool test=false;
    for (int i =0; i <l ; ++i) {
        s1l[s1[st1+i]-'a']++;
        s1r[s1[st1+i]-'a']--;
        s2l[s2[st2+i]-'a']++;
        s2r[s2[st2+i]-'a']--;
        s22r[s2[end2-i]-'a']++;
        s22l[s2[end2-i]-'a']--;
        if((s1l==s2l&&s1r==s2r))
            test|= (helper(s1,s2,st1,st1+i,st2,st2+i)&&helper(s1,s2,st1+i+1,end1,st2+i+1,end2));
        if((s1l==s22r&&s1r==s22l)){
            test|= (helper(s1,s2,st1,st1+i,end2-i,end2)&&helper(s1,s2,st1+i+1,end1,st2,end2-i-1));
        }
    }
    return mem[{st1,end1,st2,end2}]=test;
}
bool isScramble(string s1, string s2) {
    int n=s1.size();
    mem.clear();
    return helper(s1,s2,0,n-1,0,n-1);
}
};