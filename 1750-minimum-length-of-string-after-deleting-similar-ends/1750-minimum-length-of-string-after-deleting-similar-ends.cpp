class Solution {
public:
int minimumLength(string s) {
int i=0,j=s.size()-1;
while(i<j){
    if(s[i]!=s[j])
        break;
    char c=s[i];
    while(i<=j&&s[i]==c)i++;
    while(i<=j&&s[j]==c)j--;
}
return j-i+1;
}
};