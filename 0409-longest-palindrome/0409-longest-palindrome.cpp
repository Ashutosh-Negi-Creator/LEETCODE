class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto i : s){
            mp[i]++;
        }
        int odd_freq_key = 0,even_freq_values = 0,max_odd_freq = 0,odd_freq_values = 0;
        for(auto &i : mp){
            if(i.second % 2 != 0){ 
                odd_freq_values += i.second - 1;
                odd_freq_key++;
                max_odd_freq = max(max_odd_freq,i.second);
            }
            else even_freq_values += i.second;
        }
        odd_freq_values -= (max_odd_freq - 1);
        if(odd_freq_key == 0) return even_freq_values;
        else return max_odd_freq + even_freq_values + odd_freq_values;
    }
};