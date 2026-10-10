class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        vector<int> diff(nums1.size());
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        long long k = (long long)k1 + k2;

        if (accumulate(diff.begin(), diff.end(), 0LL) <= k)
            return 0;

        int l = 0, r = mx;

        while (l < r) {
            int mid = l + (r - l) / 2;
            long long need = 0;

            for (int d : diff)
                need += max(0, d - mid);

            if (need <= k)
                r = mid;
            else
                l = mid + 1;
        }

        long long ans = 0, rem = k;

        for (int d : diff) {
            int x = min(d, l);
            rem -= d - x;
            ans += 1LL * x * x;
        }

        for (int i = 0; i < diff.size() && rem > 0; i++) {
            if (diff[i] >= l) {
                ans -= 1LL * l * l;
                ans += 1LL * (l - 1) * (l - 1);
                rem--;
            }
        }

        return ans;
    }
};