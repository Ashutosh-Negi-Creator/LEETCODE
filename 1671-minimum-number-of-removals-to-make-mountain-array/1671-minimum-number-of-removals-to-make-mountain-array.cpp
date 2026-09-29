class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1);
        vector<int> lds(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j] && lis[i] < 1+lis[j]){
                    lis[i] = 1 + lis[j];
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j = i+1;j<n;j++){
                if(nums[i] > nums[j] && lds[i] < 1+lds[j]){
                    lds[i] = 1 + lds[j];
                }
            }
        }
        int maxLen = 0;
        for(int i=0;i<n;i++){
            if(lds[i] > 1 && lis[i] > 1){
                maxLen = max(maxLen,lds[i]+lis[i]-1);
            }
        }
        return n - maxLen;
    }
};