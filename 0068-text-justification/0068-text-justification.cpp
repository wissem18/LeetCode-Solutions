class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
vector<string>ans;
int i=0;
int n=words.size();
while(i<n){
    int curlength=0;
    int j=i;
    while(j<n&&curlength+words[j].size()<=maxWidth){
        curlength+=words[j].size()+1;
        j++;
    }
    int cnt=j-i;
    curlength--;
    int spaces=maxWidth-curlength;
    if(cnt==1){
        string c=words[i];
        for (int k = words[i].size(); k <maxWidth ; ++k) {
            c+=' ';
        }
        ans.push_back(c);
    }
    else if(j==n){
        string c="";
        for (int k = i; k <j-1 ; ++k) {
            c+=words[k];
            c+=' ';
        }
        c+=words[j-1];
        for (int k = 0; k < spaces; ++k) {
            c+=' ';
        }
        ans.push_back(c);
    }
    else{
        int x=spaces/(cnt-1);
        int m=spaces%(cnt-1);
        string c="";
        for (int k = i; k <i+m ; ++k) {
            c+=words[k];
            c+=' ';
            for (int l = 0; l <=x ; ++l) {
                c+=' ';
            }
        }
        for (int k = i+m; k <j-1 ; ++k) {
            c+=words[k];
            c+=' ';
            for (int l = 0; l <x ; ++l) {
                c+=' ';
            }
        }
        c+=words[j-1];
        ans.push_back(c);
    }
    i=j;
}
return ans;
}
};