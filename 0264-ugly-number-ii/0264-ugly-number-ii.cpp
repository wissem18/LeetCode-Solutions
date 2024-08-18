class Solution {
public:
int nthUglyNumber(int n) {
    set<long> s;
    s.insert(1);

    long cur = 1;
    for (int i = 0; i < n; i++) {
        cur =*s.begin();
        s.erase(s.begin());

        // Insert the next potential ugly numbers
        s.insert(cur * 2);
        s.insert(cur * 3);
        s.insert(cur * 5);
    }

    return cur;
}
};