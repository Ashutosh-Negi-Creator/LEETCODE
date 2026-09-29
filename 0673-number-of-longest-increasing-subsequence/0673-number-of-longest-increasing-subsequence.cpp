class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int n = nums.size();
        int maxLen = 0;
        vector<int> dp(n,0);
        vector<int> count(n,1); // count array will be filled with 1 as single element will make its own subsequence, if array is in decreasing order every element will form LIS on its own ans therefore no. of 1 in the count array will be ans
        for(int i=n-1;i>=0;i--){
            dp[i] = 1; //as the starting index will be included and if elemnt is only one it is LIS on its own
            for(int j = i+1;j<n;j++){
                if(nums[i]<nums[j] && dp[i]<1+dp[j]){
                    dp[i] = 1+dp[j];
                    count[i] = count[j];
                }   
                else if(nums[i] < nums[j] && dp[i] == 1+dp[j]){
                    count[i] += count[j];
                }
                maxLen = max(maxLen,dp[i]);
            }
        }
        int nlis = 0;
        for(int i = 0;i<n;i++){
            if(dp[i] == maxLen){
                nlis += count[i];
            }
        }
        return nlis;
    }
};