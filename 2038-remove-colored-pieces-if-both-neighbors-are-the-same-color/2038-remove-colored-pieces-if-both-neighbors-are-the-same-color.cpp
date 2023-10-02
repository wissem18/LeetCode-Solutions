class Solution {
public:
    bool winnerOfGame(string colors) {
int n=colors.size();
int x1=0,x2=0;
int i=0;
while(i<n){
    if(colors[i]=='A'){
        int j=i;
        while(j<n&&colors[j]=='A')
            j++;
        x1+=max(0,j-i-2);
        i=j;
    }
    else{
        int j=i;
        while(j<n&&colors[j]=='B')
            j++;
        x2+=max(0,j-i-2);
        i=j;
    }
}
return x1>x2;
}
};