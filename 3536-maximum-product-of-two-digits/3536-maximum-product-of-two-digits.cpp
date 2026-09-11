class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        if (s.size() == 2){
            int temp = n;
            int one = temp%10;
            temp /= 10;
            return temp*one;
        }
        int m1 = INT_MIN, m2 = INT_MIN,idx = 0;
        for(int i=0;i<s.size();i++){
            if((s[i]-'0') > m1){
                idx = i;
                m1 = s[i] - '0';
            }
        }
        for(int i=0;i<s.size();i++){
            if(((s[i]-'0') > m2) && (i != idx) ){
                m2 = s[i] - '0';
            }
        }
        return m1*m2;
    }
};