class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return count(0,0,nums,target);
    }
    int count(int sum,int i, vector<int>& nums,int target){
        if(nums[0] == 0 && nums[0] == target && nums.size() == 1) return 2;
        if(nums.size() == 1 && abs(target) == abs(nums[0])) return 1;
        else if(nums.size() == 1 && target != nums[0]) return 0;
        if(i == nums.size()){
            if(sum == target) return 1;
            else return 0;
        }
        int add = count(sum + nums[i],i+1,nums,target);
        int sub = count(sum - nums[i],i+1,nums,target);
        return add + sub;
    }
};