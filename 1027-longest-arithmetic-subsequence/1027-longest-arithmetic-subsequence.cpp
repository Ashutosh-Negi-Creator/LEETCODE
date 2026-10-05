class Solution {
public:
    int solve(vector<int>& nums,int curr,int diff,vector<vector<int>>& dp){
        int best = 0;
        if(dp[curr][diff] != -1) return dp[curr][diff];
        for(int k=curr+1;k<nums.size();k++){
            if(nums[curr] - nums[k] + 500 == diff){
                best = max(best,1+solve(nums,k,diff,dp));
            }
        }
        return dp[curr][diff] =  best;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;
        vector<vector<int>> dp(n+1,vector<int>(1001,-1));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff = nums[i] - nums[j] + 500;
                ans = max(ans,2+solve(nums,j,diff,dp));
            }
        }
        return ans;
    }
};