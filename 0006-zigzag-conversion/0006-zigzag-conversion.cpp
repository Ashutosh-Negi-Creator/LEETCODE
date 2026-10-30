class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> arr(numRows, vector<char>(2 * s.size())); 
        int Size = s.size();
        int left = 0;
        int bottom;
        int k = 0;
        string str;

        while (Size != 0) {
            for (int i = 0; i < numRows && k < s.size(); i++) {
                arr[i][left] = s[k];
                Size--;
                k++;
            }

            bottom = numRows - 1;
            for (int i = 0; i < numRows - 2 && k < s.size(); i++) { 
                left++;
                bottom--;
                arr[bottom][left] = s[k];
                Size--;
                k++;
            }

            left++; 
        }

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < 2 * s.size(); j++) {
                if (arr[i][j] != '\0') str += arr[i][j]; 
            }
        }

        return str;
    }
};