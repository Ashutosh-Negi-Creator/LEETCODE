class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        vector<int> ans;
        for(int i:nums){
            if(i%2 == 0) even.push_back(i);
            else odd.push_back(i);

        }
        int i=0,j=0;
        while(i<even.size() && j<odd.size()){
            ans.push_back(even[i]);
            ans.push_back(odd[j]);
            i++;
            j++;
        }
        return ans;
    }
};