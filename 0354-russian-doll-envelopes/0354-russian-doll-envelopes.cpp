class Solution {
public:
    int BinarySearch(vector<int>& tail,int target,int low,int high){
        while(low<high){
            int mid = low + (high - low)/2;
            if(tail[mid] < target){
                
                low = mid+1;
            }
            else high = mid;
        }
        return low;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        });
        vector<int> tail;
        for(auto en : envelopes){
            int low = 0;
            int high = tail.size();
            int index = BinarySearch(tail,en[1],low,high);
            if(index == tail.size()){
                tail.push_back(en[1]);
            }
            else tail[index] = en[1];
        }
        return tail.size();
    }
};