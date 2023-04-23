class Solution {
public:
bool isValid(string s) {
    int x = stoi(s);
    int n;
    if(x==0)
        n=1;
    else
    n=log10(x)+1;
    if (x >= 0 && x <= 255 && n== s.size())
        return true;
    return false;
}

vector<string> restoreIpAddresses(string s) {
    int n = s.size();
    vector<string> res;
    if (n < 4 || n > 12)
        return res;
    for (int i = 0; i < n - 3; ++i) {
        string a = s.substr(0, i + 1);
        for (int j = i + 1; j < n - 2; ++j) {
            string b = s.substr(i + 1, j - i);
            for (int k = j + 1; k < n - 1; ++k) {
                string c = s.substr(j + 1, k - j);
                string d = s.substr(k + 1, n - k);
                if (isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
                    string ans = a + "." + b + "." + c + "." + d;
                    res.push_back(ans);
                }
              //  cout<<a<<"."<<b<<"."<<c<<"."<<d<<nl;
            }
        }
    }
    return res;
}
};