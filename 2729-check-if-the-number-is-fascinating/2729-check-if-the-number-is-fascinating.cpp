class Solution {
public:
bool isFascinating(int n) {
string s1= to_string(n);
string s2= to_string(2*n);
string s3= to_string(3*n);
string s=s1+s2+s3;
    sort(s.begin(),s.end());
if(s=="123456789")
    return true;
else
    return false;
}
};