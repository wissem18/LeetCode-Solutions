class Solution {
public:
int smallestChair(vector<vector<int>> &times, int targetFriend) {
    int n = times.size();
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        events.push_back({times[i][0], i});
        events.push_back({times[i][1], -i});
    }

    sort(events.begin(), events.end());

    priority_queue<int, vector<int>, greater<int>>availableChairs; 
    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>occupiedChairs;  
    for (int i = 0; i < n; i++)
        availableChairs.push(i);

    for (auto &event: events) {
        int time = event.first;
        int friendIndex = event.second;
        
        while (!occupiedChairs.empty() &&
               occupiedChairs.top().first <= time) {
            availableChairs.push(occupiedChairs.top().second);
            occupiedChairs.pop();
        }

        if (friendIndex >= 0) { 
            int chair = availableChairs.top();
            availableChairs.pop();
            if (friendIndex == targetFriend) return chair;
            occupiedChairs.push(
                    {times[friendIndex][1],chair}); 
        }
    }

    return -1; 
}
};