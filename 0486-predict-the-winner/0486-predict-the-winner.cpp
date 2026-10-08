class Solution {
public:
    int solve(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i == j) return nums[i];  // when last element remains
        if(dp[i][j] != -1) return dp[i][j];
        int left = nums[i] - solve(i+1,j,nums,dp);
        int right = nums[j] - solve(i,j-1,nums,dp);
        return dp[i][j] = max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        if(solve(0,nums.size()-1,nums,dp) >= 0) return true;
        return false;
    }
};