class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX/2));
        long long mini = INT_MAX;
        for(int c = 0;c<n;c++){
            mini = min(mini,helper(0,c,matrix,dp));
        }
        return mini;
    }
    long long helper(int i,int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i>=matrix.size() || j>=matrix[0].size()) return INT_MAX;
        if(i == matrix.size()-1) return matrix[i][j];
        if(dp[i][j] != INT_MAX/2) return dp[i][j];
        long long down_left = matrix[i][j] + helper(i+1,j-1,matrix,dp);
        long long down = matrix[i][j] + helper(i+1,j,matrix,dp);
        long long down_right = matrix[i][j] + helper(i+1,j+1,matrix,dp);
        long long mini = min(down_left,down);
        return dp[i][j] =  min(mini,down_right);
    }
};