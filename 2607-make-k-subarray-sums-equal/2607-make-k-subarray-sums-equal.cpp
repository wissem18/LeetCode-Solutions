class Solution {
public:

vector<int> parent;
vector<int> sz;

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
    }
}
long long mnCost(vector<int>&a){
    int n=a.size();
    long long cost=0;
    sort(a.begin(),a.end());
    int mid=a[n/2];
    for (int i = 0; i < n; ++i) {
        cost+=abs(a[i]-mid);
    }
    if(n%2==0){
        long long tmp=0;
        mid=a[n/2-1];
        for (int i = 0; i < n; ++i) {
            tmp+=abs(a[i]-mid);
        }
        cost=min(cost,tmp);
    }
    return cost;
}
long long makeSubKSumEqual(vector<int>& arr, int k) {
int n=arr.size();
if(n==k)
    return 0;
    parent.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
    for (int i = 0; i < n-1; ++i) {
        union_sets(i,(i+k)%n);
    }
    unordered_map<int,vector<int>>m;
    for (int i = 0; i < n; ++i) {
          m[find_set(i)].push_back(arr[i]);
    }
    long long ans=0;
    for (auto c:m) {
      ans+= mnCost(c.second);
    }
    return ans;
}
};