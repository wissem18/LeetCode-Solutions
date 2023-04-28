class Solution {
public:
bool isSimilair(string &a,string &b){
    int cnt=0;
    for (int i = 0; i < a.size(); ++i) {
        if(a[i]!=b[i])
            cnt++;
        if(cnt>2)
            return false;
    }
   return true;
}
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
    int numSimilarGroups(vector<string>& strs) {
    int ans=strs.size();
       parent.resize(ans);
    sz.resize(ans);
        for (int i = 0; i < ans; ++i) {
            make_set(i);
        }
        for (int i = 0; i < strs.size(); ++i) {
            for (int j = i+1; j <strs.size(); ++j) {
             if(find_set(i)!=find_set(j)){
                 if(isSimilair(strs[i],strs[j])){
                     ans--;
                     union_sets(i,j);
                 }
             }
            }
        }
        return ans;
    }
};