class Solution {
public:
int sumSubarrayMins(vector<int>& arr) {
    int n=arr.size();
    int left[n], right[n];

    stack<pair<int, int> > s1, s2;

    // getting number of element strictly larger
    // than arr[i] on Left.
    for (int i = 0; i < n; ++i) {
        int cnt = 1;

        // get elements from stack until element
        // greater than arr[i] found
        while (!s1.empty() && (s1.top().first) > arr[i]) {
            cnt += s1.top().second;
            s1.pop();
        }

        s1.push({ arr[i], cnt });
        left[i] = cnt;
    }

    // getting number of element larger than arr[i] on Right.
    for (int i = n - 1; i >= 0; --i) {
        int cnt = 1;

        // get elements from stack until element greater
        // or equal to arr[i] found
        while (!s2.empty() && (s2.top().first) >= arr[i]) {
            cnt += s2.top().second;
            s2.pop();
        }

        s2.push({ arr[i], cnt });
        right[i] = cnt;
    }

    int ans = 0;
    int mod=1e9+7;
    for (int i = 0; i < n; ++i)
        ans= (ans + arr[i] * left[i] *1LL* right[i])%mod;

    return ans;
}
};