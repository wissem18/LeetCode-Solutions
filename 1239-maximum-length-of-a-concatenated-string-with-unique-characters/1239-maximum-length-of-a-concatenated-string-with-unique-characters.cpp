class Solution {
public:
int maxLength(vector<string>& arr) {
int n=arr.size();
    int ans=0;
    for (int i = 1; i <(1<<n) ; ++i) {
        string cur="";
        for (int j = 0; j < n; ++j) {
            if(cur.size()>26)
                break;
            if(i&(1<<j)){
                cur+=arr[j];
            }
        }
    sort(cur.begin(),cur.end());
        bool test=true;
        for (int j = 1; j <cur.size() ; ++j) {
            if(cur[j-1]==cur[j]){
                test=false;
                break;
            }
        }
        if(test)
            ans=max(ans,(int)cur.size());
    }
    return ans;
}
};