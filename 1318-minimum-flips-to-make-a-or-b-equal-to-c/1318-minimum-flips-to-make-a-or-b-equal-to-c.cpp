class Solution {
public:
string intToBinary(int n) {
    string r;
    while (n != 0) {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}

int minFlips(int a, int b, int c) {
    string s1 = intToBinary(a);
    string s2 = intToBinary(b);
    string s3 = intToBinary(c);
    while(s1.size()<30){
        s1="0"+s1;
    }
    while(s2.size()<30){
        s2="0"+s2;
    }
    while(s3.size()<30){
        s3="0"+s3;
    }
    int ans=0;
    for (int i = 0; i < 30; ++i) {
        if(s3[i]=='1'){
            if(s1[i]==s2[i]&&s2[i]=='0')
                ans++;
        }
        else{
            ans+=((s1[i]-'0')+(s2[i]-'0'));
        }
    }
    return ans;
}
};