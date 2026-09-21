class Solution {
public:

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void solve(string &s, int start, vector<string>& path,
               vector<vector<string>>& ans) {

        // Entire string processed
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        // Try every possible substring
        for (int end = start; end < s.size(); end++) {

            // Only choose palindrome substring
            if (isPalindrome(s, start, end)) {

                // Choose
                path.push_back(s.substr(start, end - start + 1));

                // Explore
                solve(s, end + 1, path, ans);

                // Backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> path;

        solve(s, 0, path, ans);

        return ans;
    }
};