class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;

        for (int x : nums1)
            if (x & 1)
                minOdd = min(minOdd, x);

        bool allOdd = true;
        bool allEven = true;

        for (int x : nums1) {
            if ((x & 1) == 0) {
                // even -> odd
                if (minOdd == INT_MAX || minOdd >= x)
                    allOdd = false;
            } else {
                // odd -> even
                if (minOdd >= x)
                    allEven = false;
            }
        }

        return allOdd || allEven;
    }
};