class MyQueue {
public:
    stack<int> pr, res;

    MyQueue() {

    }

    void push(int x) {
        pr.push(x);
    }

    int pop() {
        while (!pr.empty()) {
            int x = pr.top();
            pr.pop();
            res.push(x);
        }
        int ans = res.top();
        res.pop();
        while (!res.empty()) {
            int x = res.top();
            res.pop();
            pr.push(x);
        }
        return ans;
    }

    int peek() {
        while (!pr.empty()) {
            int x = pr.top();
            pr.pop();
            res.push(x);
        }
        int ans = res.top();
        while (!res.empty()) {
            int x = res.top();
            res.pop();
            pr.push(x);
        }
        return ans;
    }

    bool empty() {
        return pr.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */