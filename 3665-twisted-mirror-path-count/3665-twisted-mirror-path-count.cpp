#include <vector>

using namespace std;

class Solution {
private:
    int m, n;
    const int MOD = 1e9 + 7;
    
    // memo_dest[r][c][d] stores the precomputed empty cell destination {dest_r, dest_c}
    // d = 0 for moving Right, d = 1 for moving Down
    vector<vector<vector<pair<int, int>>>> memo_dest;
    vector<vector<int>> memo_dp;

    pair<int, int> get_destination(int r, int c, int d, const vector<vector<int>>& grid) {
        if (r >= m || c >= n) return {-1, -1};
        if (grid[r][c] == 0) return {r, c};
        
        // If already computed, return the cached result instantly
        if (memo_dest[r][c][d].first != -2) {
            return memo_dest[r][c][d];
        }

        if (d == 0) { // Moving Right hits a mirror -> redirected Down to the next row
            return memo_dest[r][c][d] = get_destination(r + 1, c, 1, grid);
        } else {      // Moving Down hits a mirror -> redirected Right to the next column
            return memo_dest[r][c][d] = get_destination(r, c + 1, 0, grid);
        }
    }

    int solve(int r, int c, const vector<vector<int>>& grid) {
        if (r == m - 1 && c == n - 1) return 1;
        if (memo_dp[r][c] != -1) return memo_dp[r][c];

        long long total_paths = 0;

        // 1. Attempt to move Right
        pair<int, int> right_dest = get_destination(r, c + 1, 0, grid);
        if (right_dest.first != -1) {
            total_paths = (total_paths + solve(right_dest.first, right_dest.second, grid)) % MOD;
        }

        // 2. Attempt to move Down
        pair<int, int> down_dest = get_destination(r + 1, c, 1, grid);
        if (down_dest.first != -1) {
            total_paths = (total_paths + solve(down_dest.first, down_dest.second, grid)) % MOD;
        }

        return memo_dp[r][c] = total_paths;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        
        // Guard check for blocked starting or ending cells
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;

        // Initialize memoization structures with optimal dimensions
        memo_dp.assign(m, vector<int>(n, -1));
        memo_dest.assign(m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-2, -2})));

        return solve(0, 0, grid);
    }
};
