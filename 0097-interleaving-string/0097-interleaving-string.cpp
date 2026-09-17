class Solution {
public:
    bool helper(string& s1,string& s2,string& s3,int i,int j,vector<vector<int>>& dp){
        if(i+j==0){
            if(i == 0 && j==0 ) return true;
            else return false;
        }
        bool first = false;
        bool second = false;

        if(dp[i][j] != -1){
            if(dp[i][j] == 1) return true;
            else return false;
        };
        if(i>0 && (s1[i-1] == s3[(i+j)-1])){ // as i+j = k, it will always be true;
            first = helper(s1,s2,s3,i-1,j,dp);
        }
        if(j>0 && (s2[j-1] == s3[i+j-1])){
            second = helper(s1,s2,s3,i,j-1,dp);
        }
        if((first || second) == true) return dp[i][j] = 1;
        else return dp[i][j] = 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(),n = s2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        if(m + n != s3.size()) return false;
        return helper(s1,s2,s3,m,n,dp);
    }
};