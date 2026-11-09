class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<int> p = {-1,-1};
        int max_p = INT_MIN;;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                int product = INT_MIN;
                int sum = INT_MIN;;
                if(i!=j && nums[i] > nums[j]){
                    sum = nums[i] + nums[j];
                }
                if(sum == target) product = nums[i]*nums[j];
                if(product > max_p){
                    p[0] = i;
                    p[1] = j;
                    max_p = product;
                }
            }
        }
        return p;
    }
};