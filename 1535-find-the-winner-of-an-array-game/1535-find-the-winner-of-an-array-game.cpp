class Solution {
public:
int getWinner(vector<int>& arr, int k) {
int n=arr.size();
deque<int>q;
    for (auto e:arr) {
       q.push_back(e);
    }
    int cnt=n;
    int nb=0;
    while (cnt--){
        int x=q.front();
        q.pop_front();
        int y=q.front();
        q.pop_front();
        if(x>y){
               nb++;
            q.push_front(x);
            q.push_back(y);
        }
        else{
                nb=1;
            q.push_front(y);
            q.push_back(x);
        }
        if(nb==k)
            return q.front();
    }
    return q.front();
}
};