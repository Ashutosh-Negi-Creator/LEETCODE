class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        int i=0;
        while(i<ransomNote.size()) {
            mp[ransomNote[i]]++;
            i++;
        }
        int j=0;
        while(j<magazine.size()){
            mp[magazine[j]]--;
            j++;
        }
        for(auto &i : mp){
            if(i.second > 0) return false;
        }
        return true;
    }
};