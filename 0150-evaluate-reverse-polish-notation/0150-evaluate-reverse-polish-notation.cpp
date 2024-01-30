class Solution {
public:
int evalRPN(vector<string>& tokens) {
stack<int>s;
string op="+*/-";
    for (int i = 0; i < tokens.size(); ++i) {
        if(op.find(tokens[i])!=string::npos){
            int x=s.top();
            s.pop();
            int y=s.top();
            s.pop();
            int p;
            if(tokens[i]=="+")
                p=x+y;
            if(tokens[i]=="-")
                p=y-x;
            if(tokens[i]=="*")
                p=x*y;
            if(tokens[i]=="/")
                p=y/x;
            s.push(p);
        }
        else{
            int x=stoi(tokens[i]);
            s.push(x);
        }
    }
    return s.top();
}
};