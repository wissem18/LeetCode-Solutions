class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int i=0,j=0;
        while(i<n){
            if(str2[j]-str1[i]==1||str2[j]-str1[i]==0||(str1[i]=='z'&&str2[j]=='a'))
                j++;
            if(j==m)
                return true;
            i++;
        }
        return false;
    }
};