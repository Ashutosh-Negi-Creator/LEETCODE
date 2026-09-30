class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int maxLen = 1;
        unordered_map<int,int> mp;
        for(int num : arr){
            int prev = num - difference;
            if(mp.count(prev) == 0) mp[num] = 1;
            else mp[num] = mp[prev] + 1;
            maxLen = max(maxLen,mp[num]);  
        }
        return maxLen;
    }
};