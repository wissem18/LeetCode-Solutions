class Solution {
public:
string addBinary(string a, string b) {
    if(a.length()>b.length()){
        while(b.length()<a.length()){
            b="0"+b;
        }
    }
    if(b.length()>a.length()){
        while(a.length()<b.length()){
            a="0"+a;
        }
    }
    int carry=0;
    string res="";
    for (int i = a.size()-1; i >=0 ; --i) {
        int x=carry+a[i]-'0'+b[i]-'0';
        res+=char(x%2+'0');
        carry=x>1;
    }
    if(carry)
        res+='1';
    reverse(res.begin(),res.end());
    return res;
}
};