class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n + 1, 0);

        for (int x : nums) {
            ans[x]++;
        }

        int duplicate = 0, missing = 0;

        for (int i = 1; i <= n; i++) {
            if (ans[i] == 2)
                duplicate = i;
            else if (ans[i] == 0)
                missing = i;
        }

        return {duplicate, missing};
    }
};