class Solution {
public:
    int countSegments(string s) {
        int state = 0,count = 0;
        for(char i:s){
            if(i == ' ') state = 0;
            else state++;
            if(state == 1) count++;
        }
        return count;
    }
};