class Solution {
public:
int minMaxDifference(int num) {
string k= to_string(num);
int i=0;
while(i<k.size()&&k[i]=='9')
    i++;
if(i!=k.size()){
    char c=k[i];
    for (int j = 0; j < k.size(); ++j) {
        if(k[j]==c){
            k[j]='9';
        }
    }
}
int mx=stoi(k);
    string s= to_string(num);
    char c=s[0];
    for (int j = 0; j < s.size(); ++j) {
        if(s[j]==c){
            s[j]='0';
        }
    }
    int mn=stoi(s);
    return mx-mn;
}
};