class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& candidates, int target, int index) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (target < 0 || index == candidates.size())
            return;

        // Include current element
        temp.push_back(candidates[index]);
        solve(candidates, target - candidates[index], index); // Reuse same element
        temp.pop_back();

        // Exclude current element
        solve(candidates, target, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return ans;
    }
};