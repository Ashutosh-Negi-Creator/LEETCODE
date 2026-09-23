class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        for(int i=n-1;i>=0;i--){
            dp[i] = 1; //as the starting index will be included and if elemnt is only one it is LIS on its own
            for(int j = i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        int ans = 0;
        for(int i: dp){
            ans = max(i,ans);
        }
        return ans;
    }
};