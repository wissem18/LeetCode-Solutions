class Solution {
public:
vector<int> sequentialDigits(int low, int high) {
int x=ceil(log10(low+1));
int y=ceil(log10(high+1));
vector<int>ans;
    for (int i = x; i <=y ; ++i) {
        for (int j = 1; j <=10-i ; ++j) {
            int cur=0;
            for (int k = j; k <j+i ; ++k) {
                cur*=10;
                cur+=k;
            }
            if(cur>=low&&cur<=high)
                ans.push_back(cur);
        }
    }
    return ans;
}
};