class Solution {
public:
vector<int> prime;

void SieveOfEratosthenes(int n) {
    prime.assign(n + 1, 1);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
        }
    }
}

bool primeSubOperation(vector<int> &nums) {
    SieveOfEratosthenes(1000);
    set<int> primes;
    for (int i = 2; i <= 1000; ++i) {
        if (prime[i])
            primes.insert(i);
    }
    int last = 1;
    for (int i = 0; i < nums.size(); ++i) {
        int cur = nums[i] - last;
        if (cur < 2) {
            if (nums[i] < last)
                return false;
            last = nums[i] + 1;
            continue;
        }
        auto x = primes.upper_bound(cur);
        if (x == primes.begin())
            return false;
        if (last - 1 >= nums[i] - *prev(x))
            return false;
        last = nums[i] - *prev(x) + 1;

    }
    return true;
}
};