class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int n : nums){
            maxi = max(maxi,n);
        }
        vector<int> freq(maxi+1,0);
        for(int i : nums){
            freq[i] += i;
        }
        vector<int> dp(freq.size()+1,-1);
        return helper(dp,freq,0);
    }
    int helper(vector<int>& dp, vector<int>& f,int i){
        if(i >= f.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int take = f[i] + helper(dp,f,i+2);
        int skip = helper(dp,f,i+1);
        return dp[i] = max(take,skip);
    }
};