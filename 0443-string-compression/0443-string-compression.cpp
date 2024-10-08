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
             string s=to_string(j-i);
             ans+=s.size()+1;
             for(int k=0;k<s.size();k++){
                 chars[index++]=s[k];
             }      
           }
           i=j;
       }
       return ans;
    }
};