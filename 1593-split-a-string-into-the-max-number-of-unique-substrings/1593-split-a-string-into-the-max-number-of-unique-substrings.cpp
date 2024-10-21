class Solution {
public:

int maxUniqueSplit(string s) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        set<string> st;
        string cur = "";
        bool isvalid = true;
        for (int j = 0; j < n - 1; j++) {
            cur += s[j];
            if ((1 << (n-j-2)) & i) {
                if (st.count(cur)) {
                    isvalid = false;
                    break;
                } else {
                    st.insert(cur);
                    cur = "";
                }
            }
        }
        cur += s[n - 1];
        if (st.count(cur)) {
            isvalid = false;
        }
        if (isvalid)
            ans=max(ans,int(st.size()+1));
    }
    return ans;
}
};