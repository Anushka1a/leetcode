
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) {
            for (int len = 2; i + len <= n; len++) {
                int j = i + len - 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;
                    int groups = d;
                    int groupLen = len / d;

                    for (int r = 0; r < groups; r++) {
                        for (int t = 0; t < groupLen / 2; t++) {
                            int left = i + r + t * d;
                            int right = i + r + (groupLen - 1 - t) * d;

                            if (s[left] != s[right]) {
                                changes++;
                            }
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        vector<vector<int>> dp(k + 1,
                               vector<int>(n + 1, 1e9));

        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {
                for (int j = 2 * (p - 1); j <= i - 2; j++) {
                    dp[p][i] = min(dp[p][i],
                        dp[p - 1][j] + cost[j][i - 1]);
                }
            }
        }

        return dp[k][n];
    }
};
