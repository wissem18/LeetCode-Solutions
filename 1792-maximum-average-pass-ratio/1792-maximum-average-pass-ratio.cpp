class Solution {
public:
    double calculateGain(int passes, int totalStudents) {
            return (double)(passes + 1) / (totalStudents + 1) -(double)passes / totalStudents;
        };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
         priority_queue<pair<double, pair<int, int>>> pq;
        for (auto c : classes) {
            pq.push({calculateGain(c[0], c[1]),{c[0], c[1]}});
        }
        
        while (extraStudents--) {
            auto [currentGain, classInfo] = pq.top();
            pq.pop();
            int passes = classInfo.first;
            int totalStudents = classInfo.second;
            pq.push({calculateGain(passes + 1, totalStudents + 1),
                          {passes + 1, totalStudents + 1}});
        }

        
        double totalPassRatio = 0;
        while (!pq.empty()) {
            auto [_, classInfo] = pq.top();
            pq.pop();
            totalPassRatio += (double)classInfo.first / classInfo.second;
        }

        return totalPassRatio / classes.size();
    }
};