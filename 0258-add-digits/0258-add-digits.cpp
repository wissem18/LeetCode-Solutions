class Solution {
public:
    int sumofdigits(int x){
    string s= to_string(x);
    int ans=0;
    for (int i = 0; i < s.size(); ++i) {
        ans+=s[i]-'0';
    }
    return ans;
}
int addDigits(int num) {
while(num>9){
    num= sumofdigits(num);
}
return num;
}
};