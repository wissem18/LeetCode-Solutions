class Solution {
public:
    struct cmp {
    cmp(int k) { this->k = k; }
    bool operator () (vector<int>&a,vector<int>&b) {
        return(a[k]>b[k]);
    }

    int k;
};
vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
    sort(score.begin(),score.end(),cmp(k));
    return score;
}
};