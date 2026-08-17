class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] == nums[j]) {
                    reverse(nums.begin() + j, nums.end());
                    reverse(nums.begin() + j, nums.end() - 1);
                    size--; 
                    j--;     
                }
            }
            count++; 
        }

        return count;
    }
};
