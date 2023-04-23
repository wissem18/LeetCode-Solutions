class Solution {
public:
string convert(string s, int numRows) {
    if(numRows==1)
        return s;
    int n=s.size();
vector<char>res[numRows];
    for (int i = 0; i < min(numRows,n); ++i) {
        res[i].push_back(s[i]);
    }
    int j=0;
    for (int i = numRows; i <n ; i+=numRows-1) {
        if(j%2==0){
            int c=numRows-2;
            for (int k =i; k <min(n,i+numRows-1) ; ++k) {
               res[c].push_back(s[k]);
               c--;
            }
            j++;
        }
        else{
            int c=1;
            for (int k =i; k <min(n,i+numRows-1) ; ++k) {
                res[c].push_back(s[k]);
                c++;
            }
            j++;
        }
    }
    string ans="";
    for (int i = 0; i < numRows; ++i) {
        for (int k = 0; k < res[i].size(); ++k) {
            ans+=res[i][k];
        }
    }
    return ans;
}
};