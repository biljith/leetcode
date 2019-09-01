class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> sum_set;
        f(candidates, sum_set, 0, 0, target);
        return res;
    }
    
    void f(vector<int>& candidates, vector<int> sum_set, int start, int sum, int target) {
        if (sum == target) {
            res.push_back(sum_set);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (sum + candidates[i] > target) break;
            sum_set.push_back(candidates[i]);
            f(candidates, sum_set, i, sum + candidates[i], target);
            sum_set.pop_back();
        }
    }
};
