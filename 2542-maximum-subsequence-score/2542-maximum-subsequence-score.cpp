class Solution {
public:
   long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
vector<pair<int,int>>p;
    for (int i = 0; i < nums1.size(); ++i) {
        p.push_back({nums2[i],nums1[i]});
    }
    sort(p.rbegin(),p.rend());
    long long ans=0;
    priority_queue<int, vector<int>, greater<int>>q;
    long long cur=0;
    for (int i = 0; i <k; ++i) {
     cur+=p[i].second;
     q.push(p[i].second);
    }
    ans=max(ans,cur*p[k-1].first);
    for (int i = k; i <p.size(); ++i) {
      cur=cur+p[i].second-q.top();
      q.pop();
      q.push(p[i].second);
      ans=max(ans,cur*p[i].first);
    }
return ans;
}
};