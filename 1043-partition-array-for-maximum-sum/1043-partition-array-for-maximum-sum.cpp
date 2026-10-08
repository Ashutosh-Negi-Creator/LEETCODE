class Solution {
public:
    int solve(int i,vector<int>& arr,int k,vector<int>& dp){
        if(i == arr.size()) return 0;
        int max_num = -1;
        if(dp[i] !=-1) return dp[i];
        int result = 0;
        for(int j=i;j<arr.size() && j<i+k;j++){
            max_num = max(max_num,arr[j]);
            int len = j-i+1;
            int cost = max_num * len + solve(j+1,arr,k,dp);
            result = max(result,cost);
        }
        return dp[i] = result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return solve(0,arr,k,dp);
    }
};