class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(matrix);
        for(int i = 1; i  < m; i++){
            for(int j = 1; j < n; j++){
                if(dp[i][j] == 1){
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]),dp[i][j-1]) + 1;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                count += dp[i][j];
            }
        }
        return count;
    }
};