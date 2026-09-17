class Solution {
public:
    bool helper(string& s, string& p,int i,int j,vector<vector<int>>& dp){
        if(j==0 && i!=0) return false;
        else if(j==0 && i == 0) return true;
        else if(i == 0){
            while(j>0){
                if(p[j-1] != '*'){
                    return dp[i][j] =  false;
                }
                j--;
            }
            return dp[i][j] = true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if((s[i-1] == p[j-1]) || p[j-1] == '?'){
            return dp[i][j] = helper(s,p,i-1,j-1,dp);
        }
        else if(p[j-1] == '*'){
            return dp[i][j] = helper(s,p,i,j-1,dp) || helper(s,p,i-1,j,dp);
        }
        else return dp[i][j]= false;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return helper(s,p,m,n,dp);
    }
};