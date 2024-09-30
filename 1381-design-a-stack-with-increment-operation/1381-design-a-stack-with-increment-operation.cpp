class CustomStack {
public:
    int mxSize;
    vector<int> stack;
    vector<int> inc;
    int lst;//index of last element which is the top of stack

    CustomStack(int maxSize) {
        mxSize = maxSize;
        inc.resize(maxSize);
        lst = -1;
    }

    void push(int x) {
        if (stack.size() == mxSize)return;
        stack.push_back(x);
        lst++;
    }

    int pop() {
        if (stack.empty())
            return -1;
        int ans = stack.back();
        int increments = inc[lst];
        ans += increments;
        inc[lst] = 0;
        lst--;
        if (lst >= 0)
            inc[lst] += increments;
        stack.pop_back();
        return ans;
    }

    void increment(int k, int val) {
        if (lst != -1) {
            int ind = min(k - 1, lst);
            inc[ind] += val;
        }
    }
};