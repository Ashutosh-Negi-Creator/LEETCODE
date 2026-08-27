class Solution {
public:
    long long helper(vector<vector<int>>& grid, vector<vector<int>>& dp,int m,int n){
        if(m <0 || n< 0) return INT_MAX;
        if(m == 0 && n== 0) return grid[m][n];
        if(dp[m][n] != -1) return dp[m][n];
        long long up = grid[m][n] + helper(grid,dp,m-1,n);
        long long left = grid[m][n] + helper(grid,dp,m,n-1);
        return dp[m][n] = min(up,left);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(grid,dp,m-1,n-1);
    }
};