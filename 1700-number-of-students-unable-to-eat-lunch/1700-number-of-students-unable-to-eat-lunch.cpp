class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
queue<int>q;
    for (int i = 0; i < students.size(); ++i) {
        q.push(students[i]);
    }
    int i=0;
    int cnt=0;
    while(i<students.size()){
        int h=q.front();
        q.pop();
        if(h!=sandwiches[i])
            q.push(h),cnt++;
        else
            i++,cnt=0;
        if(cnt>q.size())
            break;
    }
    return q.size();
}
};