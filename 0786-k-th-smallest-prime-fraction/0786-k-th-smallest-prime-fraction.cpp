class Solution {
public:
vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<>>q;
    for (int i = 0; i < arr.size(); ++i) {
        q.push({arr[i]*1.0/arr.back(), {i,arr.size()-1}});
    }
    while(k>1){
        pair<int,int>cur=q.top().second;
        q.pop();
        q.push({arr[cur.first]*1.0/arr[cur.second-1],{cur.first,cur.second-1}});//push the next smallest fraction by dividing by the next denominator
        k--;
    }
    pair<int,int>ans=q.top().second;
    return {arr[ans.first],arr[ans.second]};
}
};