class Solution {
public:

bool checkValidString(string s) {
   int mn=0,mx=0;//where mn is the min number of unmatched '(' and mx is the max number of unmatched '('
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
            mx++,mn++;
        if(s[i]==')')
            mx--,mn=max(mn-1,0);
        if(s[i]=='*')
            mx++,mn=max(mn-1,0);
        if(mx<0)//the number of ')' is more than the max '(' we can create
            return false;
    }
    return (mn==0);
    
}
};