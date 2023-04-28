class Solution {
public:
    bool reorderedPowerOf2(int n) {
          for (int i = 0; (1<<i) <=1e9; ++i) {
        int x=(1<<i);
        string m= to_string(x),k= to_string(n);
        sort(m.begin(),m.end());
        sort(k.begin(),k.end());
        if(m==k)
            return true;
    }
    return false;
    }
};