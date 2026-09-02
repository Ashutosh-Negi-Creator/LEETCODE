class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int> mp;
        int count = 0;
        for(int i =0;i<nums.size();i++){
            if(mp.count(nums[i]) == 0){
                mp[nums[i]] = i;
            }
            else{
                if(abs(i - mp[nums[i]]) == 1){
                    mp[nums[i]] = i;
                }
                else mp[nums[i]] = -1;
            }
        }
        for(auto &i : mp){
            if(i.second != -1) count++;
        }
        return count;
    }
};