
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {
                long long x = nums[j];

                long long newG = gcd(g, x);
                
                long long newL = l / gcd(l, x) * x;

                // Check before multiplication
                if (product > LLONG_MAX / x) break;
                if (newL > LLONG_MAX / newG) break;

                product *= x;
                g = newG;
                l = newL;

                if (product == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
