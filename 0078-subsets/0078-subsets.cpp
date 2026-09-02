class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0)
            return {{}};

        int last_elem = nums.back();  // Save last element
        nums.pop_back();

        vector<vector<int>> s1 = subsets(nums);
        vector<vector<int>> s2;

        for (vector<int> subset : s1) {
            subset.push_back(last_elem);
            s2.push_back(subset);
        }

        nums.push_back(last_elem); // Restore original vector

        vector<vector<int>> powerset = s1;
        powerset.insert(powerset.end(), s2.begin(), s2.end());

        return powerset;
    }
};