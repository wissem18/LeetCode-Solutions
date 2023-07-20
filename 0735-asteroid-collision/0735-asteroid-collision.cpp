class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (auto asteroid : asteroids) {
            bool test = true;
            while (!st.empty() && (st.top() > 0 && asteroid < 0)) {
                if (abs(st.top()) < abs(asteroid)) {
                    st.pop();
                    continue;
                }
                else if (abs(st.top()) == abs(asteroid)) {
                    st.pop();
                }
                test =false;
                break;
            }

            if (test) {
                st.push(asteroid);
            }
        }

        vector<int> ans (st.size());
        for (int i = ans.size() - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};