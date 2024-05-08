class Solution {
public:
vector<string> findRelativeRanks(vector<int>& score) {
vector<pair<int,int>>a;
    for (int i = 0; i < score.size(); ++i) {
        a.push_back({score[i],i});
    }
    sort(a.rbegin(),a.rend());
    vector<string>ans(score.size());
    for (int i = 0; i < a.size(); ++i) {
        if(i==0)
            ans[a[i].second]="Gold Medal";
        else if(i==1)
            ans[a[i].second]="Silver Medal";
        else if(i==2)
            ans[a[i].second]="Bronze Medal";
        else{
            ans[a[i].second]= to_string(i+1);
        }
    }
    return ans;
}
};