class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<vector<int>>> mem(
            m, vector<vector<int>>(n, vector<int>(m + n, -1)));
        return hasValidPath(grid, 0, 0, 0, mem);
    }

private:
    bool hasValidPath(const vector<vector<char>>& grid, int i, int j, int k, vector<vector<vector<int>>>& mem) {
        const int m = grid.size();
        const int n = grid[0].size();

        if (i == m || j == n) return false;
        
        k += (grid[i][j] == '(' ? 1 : -1);
        if (k < 0) return false;
        
        if (i == m - 1 && j == n - 1) return k == 0;
        
        if (mem[i][j][k] != -1) return mem[i][j][k];
        
        bool res = hasValidPath(grid, i + 1, j, k, mem) || 
                   hasValidPath(grid, i, j + 1, k, mem);
                   
        return mem[i][j][k] = res;
    }
};