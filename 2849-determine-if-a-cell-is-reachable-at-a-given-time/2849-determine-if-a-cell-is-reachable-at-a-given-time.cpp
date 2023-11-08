class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx=abs(sx-fx);
        int dy=abs(sy-fy);
        if((sx==fx)&&(sy==fy))
            return t!=1;
        return (min(dx,dy)+abs(dx-dy))<=t;
    }
};