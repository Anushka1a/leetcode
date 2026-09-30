class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        // Start or destination blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        
        // Mark visited
        grid[0][0] = 1;
        
        int distance = 1;
        
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        while (!q.empty()) {
            
            int size = q.size();
            
            while (size--) {
                
                auto [x, y] = q.front();
                q.pop();
                
                // Destination reached
                if (x == n - 1 && y == n - 1)
                    return distance;
                
                // Try all 8 directions
                for (int i = 0; i < 8; i++) {
                    
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    // Check valid and unvisited
                    if (nx >= 0 && nx < n &&
                        ny >= 0 && ny < n &&
                        grid[nx][ny] == 0) {
                        
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            
            distance++;
        }
        
        return -1;
    }
};