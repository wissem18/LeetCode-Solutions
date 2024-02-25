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

bool canTraverseAllPairs(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) {
        int x = nums[i];
        for (int j = 2; j * j <= x; ++j) {
            if (x % j == 0) {
                m[j].push_back(i);
            }
            while (x % j == 0) {
                x /= j;
            }
        }
        if (x > 1)
            m[x].push_back(i);
    }
    parent.resize(n);
    sz.resize(n);
    cmp = n;
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
    if(cmp==1)
        return true;
    for (auto &[p, arr]: m) {
        for (int i = 0; i < arr.size() - 1; ++i) {
            union_sets(arr[i], arr[i + 1]);
            if (cmp == 1)
                return true;
        }
        
    }
    
    return false;
}
};