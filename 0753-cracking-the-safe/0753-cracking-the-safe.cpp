class Solution {
public:
unordered_set<string> vis;

void dfs(string node, int &k, string &A,vector<int> &edges) {
    for (int i = 0; i < k; ++i) {
        string str = node + A[i];
        if (vis.find(str) == vis.end()) {
            vis.insert(str);
            dfs(str.substr(1), k, A,edges);
            edges.push_back(i);
        }
    }
}

string crackSafe(int n, int k) {
    string alphabet;
    for (int i = 0; i < k; ++i) {
        alphabet += char('0' + i);
    }
    if(n==1){
        return alphabet;
    }
    int l=pow(k,n);
    vector<int>edges(l);
    string startNode = string(n - 1, '0');
    dfs(startNode, k, alphabet,edges);
    string ans;
    for (int i = 0; i < l; ++i) {
        ans+=alphabet[edges[edges.size()-1-i]];
    }
        reverse(ans.begin(),ans.end());
    ans+=startNode;
    return ans;
}


};