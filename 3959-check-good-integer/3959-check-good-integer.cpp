class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum = 0, sum_sq = 0;
        while(n>0){
            sum += n%10;
            sum_sq += pow(n%10,2);
            n /= 10;
        }
        if(sum_sq - sum >= 50) return true;
        return false;
    }
};