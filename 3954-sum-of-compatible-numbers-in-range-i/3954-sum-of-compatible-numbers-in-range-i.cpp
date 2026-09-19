class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int st =max(1, n-k), end = n+k;
        int sum = 0;
        while(st<=end){
            if((abs(n-st) <= k) && ((n & st) == 0)) sum += st;
            st++;
        }
        return sum;
    }
};