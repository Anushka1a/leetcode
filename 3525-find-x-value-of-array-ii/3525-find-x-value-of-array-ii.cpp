class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {

        int n = nums.size();

        // Iterative segment tree size
        int size = 1;
        while (size < n) size <<= 1;

        vector<int> prod(2 * size, 1 % k);
        vector<array<int, 5>> cnt(2 * size);

        // Build leaves
        for (int i = 0; i < n; i++) {
            int r = nums[i] % k;
            prod[size + i] = r;
            cnt[size + i][r] = 1;
        }

        // Merge function
        auto pull = [&](int p) {
            int L = p << 1;
            int R = L | 1;

            prod[p] = (prod[L] * prod[R]) % k;

            for (int r = 0; r < k; r++) {
                cnt[p][r] = cnt[L][r];
            }

            for (int r = 0; r < k; r++) {
                int nr = (prod[L] * r) % k;
                cnt[p][nr] += cnt[R][r];
            }
        };

        // Build tree
        for (int p = size - 1; p >= 1; p--) {
            pull(p);
        }

        // Point update
        auto update = [&](int pos, int value) {
            int p = size + pos;

            int r = value % k;

            prod[p] = r;

            for (int i = 0; i < k; i++)
                cnt[p][i] = 0;

            cnt[p][r] = 1;

            p >>= 1;

            while (p) {
                pull(p);
                p >>= 1;
            }
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update nums[index]
            update(index, value);

            // Query [start, n)
            int l = size + start;
            int r = size + n;

            // Left accumulator
            int leftProd = 1 % k;
            array<int, 5> leftCnt{};

            // Right accumulator
            int rightProd = 1 % k;
            array<int, 5> rightCnt{};

            while (l < r) {

                if (l & 1) {
                    // left = merge(left, tree[l])
                    array<int, 5> temp = leftCnt;

                    for (int rem = 0; rem < k; rem++) {
                        temp[(leftProd * rem) % k] += cnt[l][rem];
                    }

                    leftCnt = temp;
                    leftProd = (leftProd * prod[l]) % k;

                    l++;
                }

                if (r & 1) {
                    --r;

                    // right = merge(tree[r], right)
                    array<int, 5> temp{};

                    for (int rem = 0; rem < k; rem++) {
                        temp[rem] = cnt[r][rem];
                    }

                    for (int rem = 0; rem < k; rem++) {
                        int nr = (prod[r] * rem) % k;
                        temp[nr] += rightCnt[rem];
                    }

                    rightCnt = temp;
                    rightProd = (prod[r] * rightProd) % k;
                }

                l >>= 1;
                r >>= 1;
            }

            // Final result = merge(left, right)
            array<int, 5> finalCnt = leftCnt;

            for (int rem = 0; rem < k; rem++) {
                int nr = (leftProd * rem) % k;
                finalCnt[nr] += rightCnt[rem];
            }

            ans.push_back(finalCnt[x]);
        }

        return ans;
    }
};