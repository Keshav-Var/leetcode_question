class Solution {
public:
    static int countMoves(vector<vector<int>>& grid, int prevData, int row, int col, vector<vector<int>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        if(row < 0 || col < 0 || row >= m || col >= n)
        return 0;
        if(grid[row][col] <= prevData)
        return 0;
        if(dp[row][col] != -1)
        return dp[row][col];
        dp[row][col] = 1 + max({countMoves(grid, grid[row][col], row-1, col+1, dp), countMoves(grid, grid[row][col], row, col+1, dp), countMoves(grid, grid[row][col], row+1, col+1, dp)});
        return dp[row][col];
    }

    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        cout<<m<<" "<<n;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            // dp = std::vector<std::vector<int>>(m, std::vector<int>(n, -1));
            ans = max(ans, countMoves(grid, -1, i, 0, dp));
        }
        return ans-1;
    }
};