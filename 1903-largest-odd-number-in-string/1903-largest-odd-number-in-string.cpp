class Solution {
public:
string largestOddNumber(string num) {
int ind=-1;
    for (int i = 0; i < num.size(); ++i) {
        if((num[i]-'0')%2){
            ind=i;
        }
    }
    if(ind==-1)
        return "";
    return num.substr(0,ind+1);
}
};