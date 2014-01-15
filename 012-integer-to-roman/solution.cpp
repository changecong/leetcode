/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Wed Jan 15 13:33:03 2014
 * Modified at:   Wed Jan 15 14:24:29 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   Input is guaranteed to be within the range from 1 to 3999.
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        
        // Symbol	Value
        //     I	1
        //     V	5
        //     X	10
        //     L	50
        //     C	100
        //     D	500
        //     M	1,000

        string result = "";
        int c = 1;
        int div = 1000;
        int dif = 5000;
        char *sym0 = "AMCXI";
        char *sym1 = "AADLV";  // "A" is used to occupy a space;

        while(num) {

            // divide into range
            // i, ii, iii
            // iv
            // v, vi, vii, viii
            // ix

            // 4
            if (4 == (num / div)) {
                result = result + sym0[c] + sym1[c];
            } else if (9 == (num / div)) {
                result = result + sym0[c] + sym0[c-1];
            } else if (num >= dif) {  // > 5
                result += sym1[c];
                result += intToRoman(num - dif);
                break;
            } else { // < 5
                int i = num / div;
                for (int j = 0; j < i; ++j) {
                    result += sym0[c];
                }
            }

            num %= div;
            div /= 10;
            dif /= 10;
            c++;
            
        }

        return result;
        
    }
};


int main() {

    Solution s;

    int num = 1954;

    string result = s.intToRoman(num);

    cout << "The input is : " << num << endl;
    cout << "The Roman number is : " << result << endl;

    return 0;
}
