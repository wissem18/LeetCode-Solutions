class Solution {
public:
 string intToBinary(int n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}
int minOperations(int n){
    string s= intToBinary(n);
    int i=s.size()-1;
    int ans=0;
    while(i>=0){
        int j=i;
        int nb=0;
        int cnt=0;
        if(s[j]=='1'){
            nb=1;
            while(j>=0&&s[j]=='1'){
                j--;
                cnt++;
            }
        }
        j--;
        while(j>=0&&s[j]=='1'){
            nb++;
                while(j>=0&&s[j]=='1'){
                    j--;
                    cnt++;
                }
           j--;
        }
        if(nb==1)
            ans+=min(cnt,2);
        else if(nb>1)
            ans+=min(nb+1,cnt);
        i=j;
    }
    return ans;
}

};