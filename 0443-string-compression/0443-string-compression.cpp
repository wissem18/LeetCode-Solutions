class Solution {
public:
int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int ans=0;
        int index=0;
       while(i<n){
           int j=i+1;
           chars[index++]=chars[i];
           while(j<n&&chars[i]==chars[j])
               j++;
           if(j-i==1)
               ans++;
           else{
             ans+=floor(log10(j-i)+1)+1;
             string s=to_string(j-i);
             for(int k=0;k<s.size();k++){
                 chars[index++]=s[k];
             }      
           }
           i=j;
       }
       return ans;
    }
};