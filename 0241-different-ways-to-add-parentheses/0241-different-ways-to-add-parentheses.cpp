class Solution {
public:
vector<int> diffWaysToCompute(string expression) {
    vector<int> res;

    if (expression.empty())
        return res;
    if (expression.size() <= 2)
        return {stoi(expression)};

    for (int i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (isdigit(c))continue;

        vector<int> left_res = diffWaysToCompute(expression.substr(0, i));
        vector<int> right_res = diffWaysToCompute(expression.substr(i + 1));

        for (int j = 0; j < left_res.size(); ++j) {
            for (int k = 0; k < right_res.size(); ++k) {
                int cur = 0;
                if (c == '+')
                    cur = left_res[j] + right_res[k];
                else if (c == '-')
                    cur = left_res[j] - right_res[k];
                else
                    cur = left_res[j] * right_res[k];
                res.push_back(cur);
            }
        }

    }
    return res;
}
};