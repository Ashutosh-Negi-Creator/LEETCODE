class Solution {
public:
    int helper(int i,int k, string& s,vector<vector<int>>& dp,vector<vector<int>>& Pal_cost){
        int n = s.size();
        int ans = INT_MAX;
        if(dp[i][k] != -1) return dp[i][k];
        if(n - i == k) return 0; // for testcase 3rd  as there n == k there we will divide it to single element and every single element is palindrome itself there fore 0 changes will be required.
        if(k == 1){
            return Pal_cost[i][n-1];
        }
        int cost = 0;
        for(int j=i;j<=n-k;j++){
            cost = Pal_cost[i][j] + helper(j+1,k-1,s,dp,Pal_cost); 
            ans = min(ans,cost);
        }
        return dp[i][k] = ans;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> Pal_cost(n,vector<int>(n,0)); // initial cost will be 0
        vector<vector<int>> dp(n,vector<int>(k+1,-1)); //dp[i][k] = minimum number of characters need to change to get k palindromic substrings, and here k+1 is used instead of k because K and also 0 is being accessed in the code and
        // 0 to k there are k+1 elements
        for(int len = 1;len <=n ; len++){
            for(int i=0;i<=n-len;i++){
                int j = i+len-1;
                if(len == 1) Pal_cost[i][j] = 0;
                else if(len == 2 && s[i] != s[j]) Pal_cost[i][j] = 1;
                else if(len > 2 && s[i] != s[j] ) Pal_cost[i][j]  = Pal_cost[i+1][j-1] + 1;
                else if(len > 2 && s[i] == s[j]) Pal_cost[i][j] = Pal_cost[i+1][j-1];
            }
        }
        return helper(0,k,s,dp,Pal_cost);
    }
};