/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Jan 13 14:08:31 2014
 * Modified at:   Mon Jan 13 15:29:46 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 * 0     6       12 ...
 * 1   5 7    11
 * 2 4   8 10  
 * 3     9

 */

#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        
        if (nRows == 1) return s;

        string result = "";
        int n = nRows * 2 - 2;

        // calculate the number of sets, if there is a mod, the actual sets would be one more
        int nSets = (int)(s.size() / n);

        // make up
        // if ((s % (nRows * 2 - 2)) !== 0) 
        int nExtra = s.size() % n;

        //
        for (int i = 0; i < nRows; ++i) {
            // for each set
            int j = 0;
            for (; j < nSets; ++j) {
                result += s[j * n + i];
                if (i != 0 && i != nRows - 1) {
                    result += s[j * n + i + (n - 2*i)];
                }
            }

            // one extra set
            if (i < nExtra) {
                result += s[j * n + i];
                if ((j * n + i + (n - 2*i)) < s.size() && i != nRows - 1) {
                    result += s[(j) * n + i + (n - 2*i)];
                }
            }

        }

        return result;
        
    }
};


int main() {

    Solution s;

    // convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
    string str = "ABCDE";
    string result = s.convert(str, 4);

    cout << "the zigzag string is: " << result << endl;

    return 0;
}
