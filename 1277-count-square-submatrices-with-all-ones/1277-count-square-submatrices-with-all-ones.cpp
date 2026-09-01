class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int total = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1) {
                    total += helper(i, j, matrix, dp);
                }
            }
        }
        return total;
    }
    
    int helper(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(row >= matrix.size() || col >= matrix[0].size()) return 0;
        if(matrix[row][col] == 0) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        
        int down = helper(row+1, col, matrix, dp);
        int right = helper(row, col+1, matrix, dp);
        int diagonal = helper(row+1, col+1, matrix, dp);
        
        return dp[row][col] = 1 + min({down, right, diagonal});
    }
};
