class Solution {
public:
int leastInterval(vector<char> &tasks, int n) {
    vector<int> occ(26, 0);
     
    for (int i = 0; i < tasks.size(); ++i) {
        occ[tasks[i] - 'A']++;
    }
    priority_queue<int>pq;
    for (int i = 0; i < 26; ++i) {
        if(occ[i])
            pq.push(occ[i]);
    }
    int ans=0;
    while(!pq.empty()){
        int cycleLength=n+1;
        vector<int>tmp;
        int cnt=0;
        while(cycleLength--&&!pq.empty()){
            int x=pq.top();
            pq.pop();
            cnt++;
            if(x-1>0)//push it for the next cycle 
                tmp.push_back(x-1);
        }
        
        //push the tmp process
        for (auto p:tmp) {
            pq.push(p);
        }
        //update ans
        if(!pq.empty())
            ans+=(n+1);
        else 
            ans+=cnt;
    }
    return ans;
}
};