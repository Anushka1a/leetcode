
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int minPrice = INT_MAX;

        vector<int> dp(budget + 1, 0);

        // Find minimum price
        for (auto &item : items) {
            minPrice = min(minPrice, item[1]);
        }

        // 0/1 Knapsack
        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            int freeItems = 0;

            // Count free items
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % factor == 0) {
                    freeItems++;
                }
            }

            // First purchase gives free items
            int profit = freeItems + 1;

            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j],
                            dp[j - price] + profit);
            }
        }

        // Use remaining budget to buy cheapest items
        int ans = 0;

        for (int j = 0; j <= budget; j++) {
            int remaining = budget - j;

            int total = dp[j] + remaining / minPrice;

            ans = max(ans, total);
        }

        return ans;
    }
};
