class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int distinct = 0;

                for (int k = i; k <= j; k++) {
                    bool found = false;

                    for (int p = i; p < k; p++) {
                        if (nums[p] == nums[k]) {
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        distinct++;
                    }
                }

                ans += distinct * distinct;
            }
        }

        return ans;
    }
};