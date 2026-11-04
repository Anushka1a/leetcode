
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long sumleft = 0, sumright = 0;

        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumleft += val;
            } else {
                right.insert(val);
                sumright += val;
            }

            while (left.size() > right.size() + 1) {
                int v = *left.rbegin();
                left.erase(left.find(v));
                sumleft -= v;
                right.insert(v);
                sumright += v;
            }

            while (left.size() < right.size()) {
                int v = *right.begin();
                right.erase(right.find(v));
                sumright -= v;
                left.insert(v);
                sumleft += v;
            }
        };

        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumleft -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                sumright -= val;
            }

            while (left.size() > right.size() + 1) {
                int v = *left.rbegin();
                left.erase(left.find(v));
                sumleft -= v;
                right.insert(v);
                sumright += v;
            }

            while (left.size() < right.size()) {
                int v = *right.begin();
                right.erase(right.find(v));
                sumright -= v;
                left.insert(v);
                sumleft += v;
            }
        };

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                long long median = *left.rbegin();

                cost[i - x + 1] =
                    median * left.size() - sumleft
                    + sumright - median * right.size();
            }
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];

                if (i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
