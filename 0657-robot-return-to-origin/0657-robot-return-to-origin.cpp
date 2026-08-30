class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int> mp;
        for(char i : moves){
            if(i == 'U') mp[i]++;
            else if(i == 'D') mp['U']--;
            else if(i == 'R') mp[i]++;
            else mp['R']--;
        }
        for(auto &i : mp){
            if(i.second != 0) return false;
        }
        return true;
    }
};