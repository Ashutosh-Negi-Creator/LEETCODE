class Solution {
public:
    int helper(vector<string>& strs,int m,int n, int i,vector<vector<vector<int>>>& dp){
        if(i == 0) return 0;
        if(m == 0 && n == 0) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int not_take = helper(strs,m,n,i-1,dp);
        int take = 0;
        int zero = 0;
        int one = 0;
        for(char k : strs[i-1]){
            if(k == '0') zero++;
            else one++;
        }
        if(zero<=m && one<=n){
            take = 1+helper(strs,m-zero,n-one,i-1,dp);
        }
        return dp[i][m][n] = max(take,not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return helper(strs,m,n,strs.size(),dp);
    }
};