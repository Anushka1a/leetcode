class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> sum(4 * n, 0);
        vector<long long> sq(4 * n, 0);
        vector<long long> lazy(4 * n, 0);

        auto update = [&](auto&& self, int node, int l, int r,
                          int ql, int qr, int val) -> void {
            if (ql <= l && r <= qr) {
                sq[node] = (sq[node] +
                    2LL * val * sum[node] +
                    1LL * (r - l + 1) * val * val) % MOD;

                sum[node] = (sum[node] +
                    1LL * (r - l + 1) * val) % MOD;

                lazy[node] += val;
                return;
            }

            int mid = (l + r) / 2;

            if (lazy[node]) {
                for (int child : {node * 2, node * 2 + 1}) {
                    int len = child == node * 2
                        ? mid - l + 1 : r - mid;

                    sq[child] = (sq[child] +
                        2LL * lazy[node] * sum[child] +
                        len * lazy[node] * lazy[node]) % MOD;

                    sum[child] = (sum[child] +
                        len * lazy[node]) % MOD;

                    lazy[child] += lazy[node];
                }
                lazy[node] = 0;
            }

            if (ql <= mid)
                self(self, node * 2, l, mid, ql, qr, val);

            if (qr > mid)
                self(self, node * 2 + 1, mid + 1, r, ql, qr, val);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last.count(nums[i]) ? last[nums[i]] : -1;

            update(update, 1, 0, n - 1, prev + 1, i, 1);

            last[nums[i]] = i;
            ans = (ans + sq[1]) % MOD;
        }

        return ans;
    }
};