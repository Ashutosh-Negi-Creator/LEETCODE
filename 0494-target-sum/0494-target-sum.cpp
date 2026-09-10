class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),INT_MAX/2);
        return count(0,nums.size()-1,nums,target);
    }
    int count(int sum,int i, vector<int>& nums,int target){
        
        if(i<0){
            if(sum == target) return 1;
            else return 0;
        }
        int add = count(sum+nums[i],i-1,nums,target);
        int sub = count(sum-nums[i],i-1,nums,target);
        return add + sub;
    }
};