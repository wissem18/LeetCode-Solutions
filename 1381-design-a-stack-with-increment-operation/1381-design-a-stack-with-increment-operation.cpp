class CustomStack {
public:
    int mxSize;
    vector<int> stack;

    CustomStack(int maxSize) {
        mxSize = maxSize;
    }

    void push(int x) {
        if (stack.size() == mxSize)return;
        stack.push_back(x);
    }

    int pop() {
        if (stack.empty())
            return -1;
        int ans = stack.back();
        stack.pop_back();
        return ans;
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, int(stack.size())); ++i) {
            stack[i] += val;
        }
    }
};