class Solution {
public:
string simplifyPath(string path) {
    deque<string>st;
    for (int i = 0; i < path.size(); ++i) {
        if(path[i]=='/')
            continue;
        string tmp="";
        while(i<path.size()&&path[i]!='/'){
            tmp+=path[i];
            i++;
        }
        if(tmp==".")
            continue;
       else if(tmp==".."){
           if(!st.empty())
            st.pop_back();
       }
       else
           st.push_back(tmp);
    }
    string res="/";
    while(!st.empty()){
        res+=st.front();
        st.pop_front();
        res+="/";
    }
    if(res!="/")
    res.pop_back();
    return res;
}
};