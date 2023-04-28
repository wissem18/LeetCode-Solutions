class Solution {
public:
vector<int> sum(string s1,string s2 ){
    if(s1.length()>s2.length()){
        while(s2.length()<s1.length()){
            s2="0"+s2;
        }
    }
    if(s2.length()>s1.length()){
        while(s1.length()<s2.length()){
            s1="0"+s1;
        }
    }
    int carry=0;
    vector<int> res;
    for (int i = s1.length()-1; i >=0 ; --i) {
        if((s1[i]-'0')+(s2[i]-'0')+carry<10){
            res.push_back((s1[i]-'0')+(s2[i]-'0')+carry);
            carry=0;
        }
        else{
            res.push_back(((s1[i]-'0')+(s2[i]-'0')+carry)-10);
            carry=1;
        }
    }
    if(carry)
    res.push_back(carry);
    reverse(res.begin(),res.end());
    return res;
}
vector<int> addToArrayForm(vector<int>& num, int k) {
vector<int>res;
string a= to_string(k);
string b="";
    for (int i = 0; i < num.size(); ++i) {
        b+=char(num[i]+'0');
    }
return sum(a,b);
}
};