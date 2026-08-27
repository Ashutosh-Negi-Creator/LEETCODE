class Solution {
public:
    int helper(vector<vector<int>>& og, vector<vector<int>>& dp,int m,int n){
        if(m < 0 || n < 0) return 0;
        if(m == 0 && n == 0 && og[m][n] != 1) return 1;
        if(m == 0 && n == 0 && og[m][n] == 1) return 0;
        if(og[m][n] == 1) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int up = helper(og,dp,m-1,n);
        int left = helper(og,dp,m,n-1);
        return dp[m][n] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();  
        int n = obstacleGrid[0].size();  
    
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(obstacleGrid,dp,m-1,n-1);
    }
};