class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int maxi = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1'){
                    maxi = max(maxi,helper(i,j,matrix,dp));
                }
            }
        }
        if(maxi == INT_MIN) return 0;
        return maxi*maxi;
    }
    int helper(int row,int col,vector<vector<char>>& matrix,vector<vector<int>>& dp){
        if(row >= matrix.size() || col >= matrix[0].size()) return 0;
        if(matrix[row][col] == '0') return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int down = helper(row+1,col,matrix,dp);
        int right = helper(row,col+1,matrix,dp);
        int diagonal = helper(row+1,col+1,matrix,dp);
        return dp[row][col] = 1+min(down,min(right,diagonal));
    }
};