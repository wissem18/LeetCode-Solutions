class Solution {
public:
   vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
int n=nums1.size();
int m=nums2.size();
priority_queue<pair<int,pair<int,int>>>q;
q.push({-(nums1[0]+nums2[0]),{0,0}});
set<pair<int,int>>s;
s.insert({0,0});
vector<vector<int>>ans;
while(k--&&!q.empty()){
    auto cur=q.top();
    q.pop();
    int i=cur.second.first;
    int j=cur.second.second;
    ans.push_back({nums1[i],nums2[j]});
    if(i+1<n&&!s.count({i+1,j})){
        s.insert({i+1,j});
        q.push({-(nums1[i+1]+nums2[j]),{i+1,j}});
    }
    if(j+1<m&&!s.count({i,j+1})){
        s.insert({i,j+1});
        q.push({-(nums1[i]+nums2[j+1]),{i,j+1}});
    }
}
return ans;
}
};