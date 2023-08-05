class Solution {
public:
 int rec(int i,int n,vector<int>occ){
    if(i==n)
        return 0;
    int ans=0;
    for (int j = 0; j < occ.size(); ++j) {
        if(occ[j]){
            occ[j]--;
            ans+=1+rec(i+1,n,occ);
            occ[j]++;
        }
    }
return ans;
}
int numTilePossibilities(string tiles) {
vector<int>occ(26,0);
int n=tiles.size();
    for (int i = 0; i < n; ++i) {
        occ[tiles[i]-'A']++;
    }
    return rec(0,n,occ);
}
};