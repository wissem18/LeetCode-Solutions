# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Bitwise OR properties
# Approach
<!-- Describe your approach to solving the problem. -->
first we must convert the numbers into their binary representation then using the bitwise OR properties 0 OR 0 = 0 and other combinations gives 1 so we loop into the binary representations and if the ith bit of c is set and the two ith bits of a and b are unset so we flip one bit to get 1 in c. 
if the ith bit of c is unset so the ith bits of a and b must be unset so if any bit set we must flip it to obtain the unset bit in c .
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
O(logN)
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
O(N)
# Code
```
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
```
