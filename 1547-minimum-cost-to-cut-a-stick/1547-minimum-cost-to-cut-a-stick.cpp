class Solution {
public:
    int solve(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
        if(i == j-1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = INT_MAX;
        for(int k = i+1; k <= j-1;k++){
            int cost = abs(arr[j] - arr[i]);
            int left = solve(i,k,arr,dp);
            int right = solve(k,j,arr,dp);
            res = min(res,cost + left + right);
        }
        return dp[i][j] = res;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m+2,vector<int>(m+2,-1));
        vector<int> arr(cuts.size() + 2);
        for(int i=1;i<arr.size()-1;i++){
            arr[i] = cuts[i-1];
        }
        arr[0] = 0;
        arr[arr.size()-1] = n;
        return solve(0,arr.size()-1,arr,dp);
    }
};