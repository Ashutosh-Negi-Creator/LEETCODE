class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return nums;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,-1);
        vector<int> parent(n,-1);
        int maxLen = 0;
        int startIndex = -1;
        for(int i=n-1;i>=0;i--){
            dp[i] = 1;
            for(int j = i+1;j<n;j++){
                if(nums[j]%nums[i] == 0 && dp[i]<1+dp[j]){
                    dp[i] = 1+dp[j];
                    parent[i] = j;
                }
                if(maxLen < dp[i]){
                    maxLen = dp[i];
                    startIndex = i;
                }
            }
        }
        vector<int> ans;
        while(startIndex != -1){
            ans.push_back(nums[startIndex]);
            startIndex = parent[startIndex];
        }
        return ans;
    }
};