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

vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
parent.resize(n);
sz.resize(n);
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
    sort(edgeList.begin(),edgeList.end(),[&](vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    });
    vector<vector<int>>qi(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
        qi[i]=queries[i];
        qi[i].push_back(i);
    }
    sort(qi.begin(),qi.end(),[&](vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    });
    vector<bool>ans(queries.size());
    int j=0;
    for (int i = 0; i < qi.size(); ++i) {
            while(j<edgeList.size()&&edgeList[j][2]<qi[i][2]){
                union_sets(edgeList[j][0],edgeList[j][1]);
                j++;
            }
            ans[qi[i][3]]=(find_set(qi[i][0])==find_set(qi[i][1]));
        }
    return ans;
}

};