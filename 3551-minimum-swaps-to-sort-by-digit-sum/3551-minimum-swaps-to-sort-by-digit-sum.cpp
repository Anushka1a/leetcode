class Solution {
public:
    int sumDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<pair<int, int>, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({{sumDigits(nums[i]), nums[i]}, i});
        }

        sort(v.begin(), v.end());

        int swaps = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i] || v[i].second == i)
                continue;

            int cycle = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = v[j].second;
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};