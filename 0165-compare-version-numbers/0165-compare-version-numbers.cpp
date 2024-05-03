class Solution {
public:
int compareVersion(string version1, string version2) {
    vector<int> a, b;
    string cur = "";
    for (int i = 0; i < version1.size(); ++i) {
        if (version1[i] == '.') {
            int x = stoi(cur);
            a.push_back(x);
            cur = "";
        } else {
            cur += version1[i];
        }
    }
    if (!cur.empty()) {
        int x = stoi(cur);
        a.push_back(x);
        cur = "";
    }
    cur = "";
    for (int i = 0; i < version2.size(); ++i) {
        if (version2[i] == '.') {
            int x = stoi(cur);
            b.push_back(x);
            cur="";
        } else {
            cur += version2[i];
        }
    }
    if (!cur.empty()) {
        int x = stoi(cur);
        b.push_back(x);
        cur="";
    }
   
    while(a.size()<b.size())a.push_back(0);
    while(b.size()<a.size())b.push_back(0);
    int i = 0;
    while (i < a.size() && i < b.size()) {
        if (a[i] < b[i])
            return -1;
        if (a[i] > b[i])
            return 1;
        i++;
    }
    
    return 0;
}
};