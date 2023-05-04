class Solution {
public:
string predictPartyVictory(string senate) {
  queue<int>qr,qd;
  int n=senate.size();
    for (int i = 0; i < n; ++i) {
        if(senate[i]=='R')
            qr.push(i);
        else
            qd.push(i);
    }
    while(!qd.empty()&&!qr.empty()){
        int r=qr.front();
        qr.pop();
        int d=qd.front();
        qd.pop();
        if(r<d){
            qr.push(r+n);
        }
        else{
            qd.push(d+n);
        }
    }
    if(qd.empty())
        return "Radiant";
    else
        return "Dire";
}
};