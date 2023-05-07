class Solution {
public:
int addMinimum(string word) {
    int ans=0;
    int n=word.size();
    for (int i = 0; i <n ; ++i) {
        if(word[i]=='a'){
            if(i+1<n&&word[i+1]=='b'){
                if(!(i+2<n&&word[i+2]=='c')){
                    ans+=1;
                    i++;
                }
                else{
                    i+=2;
                }
            }
            else{
                if(i+1<n&&word[i+1]=='c'){
                    ans+=1;
                    i++;
                }
                else
                    ans+=2;
            }
        }
       else if(word[i]=='b'){
            if(i+1<n&&word[i+1]=='c')
                i++;
            else {
                ans+=1;
            }
            if(!(i-1>0&&word[i-1]=='a')){
                ans++;
            }
        }
        else if(word[i]=='c'){
         if(!(i-1>0&&(word[i-1]=='a'||word[i-1]=='b')))
             ans+=2;
        }
    }
    return ans;
}
};