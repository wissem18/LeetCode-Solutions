class Solution {
public:
vector<int> parent;
vector<int> sz;
int cmp;

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        cmp--;
    }
}
int spf[100005];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<100005; i++)
        spf[i] = i;
    for (int i=4; i<100005; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<100005; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<100005; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
unordered_map<int, vector<int>> m;
void getFactorization(int x,int ind)
{
    while (x != 1)
    {
        m[spf[x]].push_back(ind);
        x = x / spf[x];
    }
}

bool canTraverseAllPairs(vector<int> &nums) {
    int n = nums.size();
    sieve();
    for (int i = 0; i < n; ++i) {
        int x = nums[i];
        getFactorization(x,i);
    }
    parent.resize(n);
    sz.resize(n);
    cmp = n;
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
    for (auto &[p, arr]: m) {
        for (int i = 0; i < arr.size() - 1; ++i) {
            union_sets(arr[i], arr[i + 1]);
            if (cmp == 1)
                return true;
        }
    }
    if(cmp==1)
        return true;
    return false;
}
};