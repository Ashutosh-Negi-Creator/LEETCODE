class Solution {
public:
    int helper(int amount, vector<int>& coins,int i,vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(amount <0) return 0;
        if(i <= 0)  return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        int take  = 0;
        if(coins[i-1] <= amount){
            take = helper(amount - coins[i-1],coins,i,dp);
        }
        int not_take = helper(amount,coins,i-1,dp);
        return dp[i][amount] = not_take + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return helper(amount,coins,n,dp);
    }
};