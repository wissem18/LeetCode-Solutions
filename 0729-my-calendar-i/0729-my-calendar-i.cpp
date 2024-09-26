class MyCalendar {
public:
    vector<pair<int, int>> events;

    MyCalendar() {
    }

    bool book(int start, int end) {
        end--;
        for (auto &[st, e]: events) {
            if ((start >= st && start <= e) || (end >= st && end <= e) || (start <= st && end >= e))
                return false;
        }
        events.push_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */