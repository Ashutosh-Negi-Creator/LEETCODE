class Solution {
public:
    int helper(int i,int n,vector<vector<int>>& dp){
        if(n == 0) return 0;
        if(i<=0) return INT_MAX;
        int take = INT_MAX/2;
        if(dp[i][n] != -1) return dp[i][n];
        if(i*i<=n){
            take = 1 + helper(i,n-i*i,dp);
        }
        int not_take = helper(i-1,n,dp);
        return dp[i][n] = min(take,not_take);
    }
    int numSquares(int n) {
        int max_sq = sqrt(n);
        vector<vector<int>> dp(max_sq + 1,vector<int>(n+1,-1));
        return helper(max_sq,n,dp);
    }
};