class Solution {
public:
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
stack<int>a;
int n=pushed.size();
int j=0;
    for (int i = 0; i < n; ++i) {
        while(j<n&&(a.empty()||a.top()!=popped[i])){
            a.push(pushed[j]);
            j++;
        }
        if(a.top()==popped[i]){
            a.pop();
        }
    }
    return (a.empty());
}
};