class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int c = 0;
        for(char i : s){
            if(i == '(') c++;
            else if(i == ')') c--;
            maxi = max(maxi,c);
        }
        return maxi;
    }

};