class Solution {
public:
        int bestClosingTime(string customers) {
        int n=customers.size();
        int p = 0;
        for (int i = 0; i < n; ++i) {
            if(customers[i]=='Y')
                p++;
        }
        int mn = p;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            char c = customers[i];
            if (c == 'Y') {
                p--;
            } else {
                p++;
            }

           
            if (p < mn) {
                ans = i + 1;
                mn = p;
            }
        }

        return ans;
    }
};