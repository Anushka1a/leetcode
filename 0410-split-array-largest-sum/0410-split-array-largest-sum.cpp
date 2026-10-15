class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, LLONG_MAX)
        );

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            for (int i = parts; i <= n; i++) {
                for (int j = parts - 1; j < i; j++) {
                    if (dp[parts - 1][j] == LLONG_MAX)
                        continue;

                    long long sum = pref[i] - pref[j];

                    dp[parts][i] = min(
                        dp[parts][i],
                        max(dp[parts - 1][j], sum)
                    );
                }
            }
        }

        return (int)dp[k][n];
    }
};