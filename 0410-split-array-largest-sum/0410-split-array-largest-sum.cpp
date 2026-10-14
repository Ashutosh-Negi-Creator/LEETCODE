class Solution {
public:
    int solve(int i,int k,vector<int>& nums,vector<vector<int>>& dp){
        int n = nums.size();
        if(dp[i][k] != -1) return dp[i][k];
        if(k == 1){
            int sum = 0;
            for(int t=i;t<n;t++){
                sum += nums[t];
            }
            return sum;
        }
        int ans = INT_MAX;
        int curr_sum = 0;
        int max_sum = INT_MIN;
        for(int j=i;j<=n-k;j++){
            curr_sum += nums[j];
            int rem_sum = solve(j+1,k-1,nums,dp);
            max_sum = max(rem_sum,curr_sum);
            ans = min(ans,max_sum);
        }
        return dp[i][k] = ans;

    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector(k+1,-1));
        return solve(0,k,nums,dp);
    }
};