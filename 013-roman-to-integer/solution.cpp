/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Wed Jan 15 14:30:28 2014
 * Modified at:   Wed Jan 15 14:57:26 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
  
        // all sum beside 4 and 9
        
        // Symbol	Value
        //     I	1
        //     V	5
        //     X	10
        //     L	50
        //     C	100
        //     D	500
        //     M	1,000
        
        if ("" == s) return 0;
        
        map<char, int> roman;
        char *sym = "IVXLCDM";
        int val[7] = {1, 5, 10, 50, 100, 500, 1000};
        for (int i = 0; i < 7; ++i) {
            roman[sym[i]] = val[i];
        }

        int result = 0;

        if(roman[s[0]] < roman[s[1]]) {  // 4 or 9
            return (roman[s[1]] - roman[s[0]]) + romanToInt(s.substr(2, s.size() - 2));
                
        } else {
            return roman[s[0]] + romanToInt(s.substr(1, s.size() - 1));
        }


    }
};


int main() {

    Solution s;

    string str = "MMXIV";

    int result = s.romanToInt(str);

    cout << "The input Roman numeral is : " << str << endl;
    cout << "The conversion result is : " << result << endl;

    return 0;
}
