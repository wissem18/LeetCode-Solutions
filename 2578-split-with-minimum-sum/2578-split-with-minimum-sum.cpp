class Solution {
public:
int splitNum(int num) {
string x= to_string(num);
sort(x.begin(),x.end());
string c="",d="";
    for (int i = 0; i < x.size(); i+=2) {
      c+=x[i];
      if(i+1<x.size())
          d+=x[i+1];
    }
    return stoi(c)+stoi(d);
}
};