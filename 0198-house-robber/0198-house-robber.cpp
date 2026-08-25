class Solution {
public:
    int helper(vector<int>& dp, int i,vector<int>& nums){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + helper(dp,i+2,nums);
        int skip = helper(dp,i+1,nums);
        return dp[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return helper(dp,0,nums);
    }
};