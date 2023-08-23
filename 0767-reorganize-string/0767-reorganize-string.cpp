class Solution {
public:
    string reorganizeString(string s) {
    int n=s.size();
    vector<int>occ(26,0);
    for (int i = 0; i < n; ++i) {
        occ[s[i]-'a']++;
    }
    int mx=0,mxl=0;
    for (int i = 0; i < 26; ++i) {
        if(occ[i]>mx){
            mx=occ[i];
            mxl=i;
        }
    }
    if(mx>(n+1)/2)
        return "";
    else{
        int ind=0;
     while(occ[mxl]){
         s[ind]=char('a'+mxl);
         ind+=2;
         occ[mxl]--;
     }
        for (int i = 0; i < 26; ++i) {
            while(occ[i]){
                if(ind>=n)
                    ind=1;
                s[ind]=char('a'+i);
                ind+=2;
                occ[i]--;
            }
        }
        return s;
    }
}
};