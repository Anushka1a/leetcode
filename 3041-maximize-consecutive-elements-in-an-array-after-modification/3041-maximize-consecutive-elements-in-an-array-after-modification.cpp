
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : nums) {

            int keep = dp[x - 1] + 1;
            int increase = dp[x] + 1;

            dp[x + 1] = max(dp[x + 1], increase);
            dp[x] = max(dp[x], keep);

            ans = max(ans, max(dp[x], dp[x + 1]));
        }

        return ans;
    }
};
