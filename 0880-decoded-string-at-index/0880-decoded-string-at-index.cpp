class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long n = 0;
        for (auto c : s) {
            if (isdigit(c)) 
                n *= (c - '0');
            else 
                n++;
        }

        for (int i =s.size() - 1; i >= 0; i--) {
            if (isdigit(s[i])) {
                n /= (s[i] - '0');
                k = k % n;
            } else {
                if (k == 0 || k == n)
                    return string("") + s[i];
                n--;
            }
        }

        return ""; 
    }
};