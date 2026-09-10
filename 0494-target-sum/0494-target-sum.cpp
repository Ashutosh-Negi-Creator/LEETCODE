class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*2D dp array will be used as there are 2 parameters that are changing, one is sum and other is i, therefore dp should have been filled as  dp[i][sum] but as sum can also be in negative and so there is no negative indexing , we will use offset, and will offset values by total_sum of that array, and dp array size would be dp[nums.size()][2001] as the target is from -1000 to 1000 therefore maximum numbers can be 1000......0.....1000 = toatl number will be 2001*/
        int t_sum = 0;
        for(int i : nums){
            t_sum += i;
        }
        vector<vector<int>> dp(nums.size(),vector<int>(2001,INT_MAX));
        return count(0,nums.size()-1,nums,target,dp,t_sum);
    }
    int count(int sum,int i, vector<int>& nums,int target,vector<vector<int>>& dp,int t_sum){ 
        if(i<0){
            if(sum == target) return 1;
            else return 0;
        }
        if(dp[i][sum+t_sum] != INT_MAX) return dp[i][sum+t_sum]; 
        int add = count(sum+nums[i],i-1,nums,target,dp,t_sum);
        int sub = count(sum-nums[i],i-1,nums,target,dp,t_sum);
        return dp[i][sum+t_sum] =  add + sub;
    }
};