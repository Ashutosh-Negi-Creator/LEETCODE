class Solution {
public:
    int helper(int start,string& s,vector<int>& dp,vector<vector<bool>>& isPal){
        if(start == s.size()) return 0;

        if(dp[start] != -1) return dp[start];
        
        int ans = INT_MAX/2;
        
        for(int end = start;end<s.size();end++){
            if(isPal[start][end]){// will take substring form start to end only
                ans = min(ans,1+helper(end+1,s,dp,isPal));
            }
        }
        return dp[start] = ans;  
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        vector<vector<bool>> isPal(n,vector<bool>(n,false));
        for(int len = 1;len<=n;len++){
            for(int i=0;i<=n-len;i++){ //start point
                int j = i+len-1; //end point
                if(len == 1){  // single character will always be palindrome
                    isPal[i][j] = true;
                }
                else if(len == 2 && s[i] == s[j]){ //lenght of 2 string have to be equal with each other to be palindrome,
                    isPal[i][j] = true;               // e.g) 'aa' here both are equal 
                }
                else if(s[i] == s[j] && isPal[i+1][j-1]){ // s= 'abbccbba' here first see if s[0] == s[n-1] if not , it's not palindrome, if yes then also check dp[i+1] == dp[j-1] that is i was 0 now i = 1 and j was n-1(7) so now j=6
                    isPal[i][j] = true;
                }
            }
        }
        return helper(0,s,dp,isPal) -1; // doing -1 because partition will also be added at the end which should not be counted;
        
    }
};