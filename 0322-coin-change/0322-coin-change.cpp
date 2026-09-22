class Solution {
public:
    int helper(vector<int>& coins,int cap,int i,vector<vector<int>>& dp){
        if(cap == 0) return 0;
        if(i==0) return INT_MAX/2;
        if(dp[i][cap] != -1) return dp[i][cap];
        int take = INT_MAX/2;
        int not_take = 0;
        if(coins[i-1] <= cap){
            take = 1+ helper(coins,cap-coins[i-1],i,dp);
            not_take = helper(coins,cap,i-1,dp);
        }
        else not_take = helper(coins,cap,i-1,dp);
        return dp[i][cap] = min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans = helper(coins,amount,coins.size(),dp);
        if(ans >= INT_MAX/2) return -1;
        return ans;
    }
};