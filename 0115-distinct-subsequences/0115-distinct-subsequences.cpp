class Solution {
public:
    // int helper(string s, string t, int i, int j,vector<vector<int>>& dp){
    //     if(i==0 && j!=0) return 0; // means s string has finished meanwhile j has not
    //     if(j == 0) return 1; // means j string has finished ans so s can generate t ;
    //     if(dp[i][j] != 0) return dp[i][j];
    //     if(s[i-1] == t[j-1]){
    //         return dp[i][j] =  helper(s,t,i-1,j-1,dp) + helper(s,t,i-1,j,dp);
    //     }
    //     else return dp[i][j]=helper(s,t,i-1,j,dp);
    // }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<unsigned long long>> dp(m+1,vector<unsigned long long>(n+1,0));
        for(int i=0;i<=m;i++) dp[i][0] = 1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        } 
        return dp[m][n];  
    }
};