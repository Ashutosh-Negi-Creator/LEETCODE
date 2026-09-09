class Solution {
public:
    int reverseBits(int n) {
        int result = 0;
        for(int i=0;i<32;i++){
            int lsb = n & 1;
            int rev_lsb = lsb << (31 - i);
            result = result | rev_lsb;
            n = n >> 1;
        }
        return result;
    }
};