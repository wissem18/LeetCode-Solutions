class Solution {
public:
bool isPathCrossing(string path) {
set<pair<int,int>>s;
s.insert({0,0});
int x=0,y=0;
    for (int i = 0; i < path.size(); ++i) {
        if(path[i]=='N')
            y++;
        if(path[i]=='S')
            y--;
        if(path[i]=='E')
            x++;
        if(path[i]=='W')
            x--;
        if(s.count({x,y}))
            return true;
        s.insert({x,y});
    }
    return false;
}
};