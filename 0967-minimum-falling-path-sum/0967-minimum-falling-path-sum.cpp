class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){  
                if(j == 0) grid[i][j] = min(grid[i-1][j], grid[i-1][j+1]) + grid[i][j];
                else if(j == n-1) grid[i][j] = min(grid[i-1][j], grid[i-1][j-1]) + grid[i][j];
                else grid[i][j] = min(grid[i-1][j], min(grid[i-1][j-1], grid[i-1][j+1])) + grid[i][j];
            }
        }
        int ans = INT_MAX;
        for(int j = 0; j < n; j++){
            ans = min(ans, grid[m-1][j]);
        }
        return ans;
    }
};