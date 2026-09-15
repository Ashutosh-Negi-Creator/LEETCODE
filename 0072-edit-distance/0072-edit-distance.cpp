class Solution {
public:
    int minDistance(string word1, string word2) {
        int i = word1.size(),j=word2.size();
        if(i == 0) return j; //if word 1 = null then have to insert j (word 2 length) to make word1 = word2;
        if(j == 0) return i; // number of deletions required if nothing matches;
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // Base cases
        for(int i=0; i<=m; i++) dp[i][0] = i; // delete all chars
        for(int j=0; j<=n; j++) dp[0][j] = j; // insert all chars
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int ins = 1 + dp[i][j-1]; //Insetion
                    int del = 1 + dp[i-1][j]; //Deletion
                    int rep = 1 + dp[i-1][j-1]; //Replace
                    dp[i][j] = min({ins,del,rep});
                }
            }
        }
        return dp[m][n];
    }
};