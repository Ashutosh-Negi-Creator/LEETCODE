class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> vec;
        for(int i:nums){
            if(i%2 == 0) vec.push_back(i);
        }
        for(int i:nums){
            if(i%2 != 0) vec.push_back(i);
        }
        return vec;
    }
};