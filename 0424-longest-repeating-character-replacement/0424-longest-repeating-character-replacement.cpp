class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int l = 0,r=0,max_freq = 0, max_len = 0;
        for(r=0;r<s.size();r++){
            mp[s[r]]++;
            max_freq = max(max_freq,mp[s[r]]);
            while(r-l+1 - max_freq > k ){  // r-l+1(win size) - max_freq ==> no. of char needed for the replacement
                mp[s[l]]--;
                l++;
            }
            max_len = max(r-l+1,max_len);
        }
        return max_len;
    }

};