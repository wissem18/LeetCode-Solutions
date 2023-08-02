class Solution {
public:
vector<string> readBinaryWatch(int turnedOn) {
vector<string>ans;
    for (int i = 0; i < (1<<10); ++i) {
      if(__builtin_popcount(i)==turnedOn){
          int h=0;
        for (int j = 0; j < 4; ++j) {
            if(i&(1<<j))
                h+=(1<<j);
        }
        if(h>=12)
            continue;
        int m=0;
        for (int j = 4; j <10 ; ++j) {
            if(i&(1<<j))
                m+=(1<<(j-4));
        }
        if(m>=60)
            continue;
        string cur= to_string(h)+":";
        if(m<10)
            cur+="0";
        cur+=to_string(m);
        ans.push_back(cur);
      }
    }
    return ans;
}
};