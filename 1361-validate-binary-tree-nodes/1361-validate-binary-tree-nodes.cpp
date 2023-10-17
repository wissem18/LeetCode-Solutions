class Solution {
public:
    vector<int> parent;
int cnt;
void make_set(int v) {
    parent[v] = v;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
bool union_sets(int a, int b) {
    int para = find_set(a);
    int parb = find_set(b);
    if(parb!=b)//already b have another parent connected with it
        return false;
    if(para==parb)// a and b are already in the same component so if we join them we create a cycle
        return false;
    parent[b]=a;
    cnt--;
    return true;
}
bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
cnt=n;
parent.resize(n);
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
    for (int i = 0; i < n; ++i) {
        int l=leftChild[i];
        int r=rightChild[i];
        if(l!=-1){
            if(!union_sets(i,l))
                return false;
        }
        if(r!=-1){
            if(!union_sets(i,r))
                return false;
        }
    }
    return cnt==1;
}
};