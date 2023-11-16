class Solution {
public:

string intToBinary(int n) {
    string r;
    while (n != 0) {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}
string findDifferentBinaryString(vector<string> &nums) {
    int n = nums.size();
    for (int i = 0; i < (1 << n); ++i) {
        string cur = intToBinary(i);
        while (cur.size() < n)cur = "0" + cur;
        if(find(nums.begin(),nums.end(),cur)==nums.end())return cur;
    }
    return "";
}
};