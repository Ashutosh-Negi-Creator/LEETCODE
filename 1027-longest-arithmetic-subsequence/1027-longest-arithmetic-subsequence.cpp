class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        vector<vector<int>> dp(n+1,vector<int>(1001,0));
        for(int i = 0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i] - nums[j];
                int diffIndx = diff + 500;
                dp[i][diffIndx] = max(dp[i][diffIndx],1+dp[j][diffIndx]);
                maxlen = max(dp[i][diffIndx],maxlen);
            }
            
        }
        return 1+maxlen;
    }
};