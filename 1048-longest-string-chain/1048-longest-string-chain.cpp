class Solution {
public:
    bool isPred(string& a,string& b){
        int m = a.size();
        int n = b.size();
        if(n-m != 1) return false;
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(a[i] == b[j]){
                i++;
            }
            j++;
        }
        return (i == m);
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(), [](const string& a,const string& b){
            return a.size()<b.size();
        });
        int n = words.size();
        vector<int> dp(n,0);
        int maxLen = 1;
        for(int i=0;i<n;i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                if(isPred(words[j],words[i])){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            maxLen = max(dp[i],maxLen);
        }
        return maxLen;
    }
};