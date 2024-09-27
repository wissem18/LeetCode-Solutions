class MyCalendarTwo {
public:
    vector<pair<int, int>> events;
    vector<pair<int, int>> double_events;

    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        end--;
        for (auto &[st, e]: double_events) {
            if ((start >= st && start <= e) || (end >= st && end <= e) || (start <= st && end >= e))
                return false;
        }
        for (auto &[st, e]: events) {
            if ((start >= st && start <= e) || (end >= st && end <= e) || (start <= st && end >= e))
                double_events.push_back(make_pair(max(start, st), min(end, e)));
        }
        events.push_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */