class Solution {
public:
vector<vector<int>> res;

void helper(int index, int remSum, vector<int> &combination, vector<int> &candidates) {
    if (remSum == 0) {
        res.push_back(combination);
        return;
    }
    for (int i = index; i < candidates.size() && remSum >= candidates[i]; ++i) {
        if (i == index || candidates[i] != candidates[i - 1]) {
            combination.push_back(candidates[i]);
            helper(i+1, remSum - candidates[i], combination, candidates);
            combination.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> combination;
    helper(0,target,combination,candidates);
    return res;
}
};