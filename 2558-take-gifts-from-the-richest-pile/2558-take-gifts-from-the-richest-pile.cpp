class Solution {
public:
long long pickGifts(vector<int>& gifts, int k) {
priority_queue<int>q;
    long long sum=0;
    for (int i = 0; i < gifts.size(); ++i) {
        q.push(gifts[i]);
    }
    while(k){
        int c=q.top();
        q.pop();
        int x= sqrt(c);
        q.push(x);
        k--;
    }
    while(!q.empty()){
        int c=q.top();
        q.pop();
        sum+=c;
    }
    return sum;
}
};