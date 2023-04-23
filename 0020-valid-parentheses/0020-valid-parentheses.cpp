class Solution {
public:
bool isValid(string s) {
    if(s.length()%2)
        return false;
    stack<char> st;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
            st.push(s[i]);
        else if(!st.empty())
        {
            char c=st.top();
            if((c=='('&&s[i]==')')||(c=='{'&&s[i]=='}')||(c=='['&&s[i]==']'))
                st.pop();
            else
                return false;
        }
        else
        return false;
    }
    return st.empty();
    }
};