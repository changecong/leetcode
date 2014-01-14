/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Jan 14 10:33:16 2014
 * Modified at:   Tue Jan 14 11:43:17 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
using namespace std;

class Solution {
private:
    int MAX_ = 0x7fffffff;  // 2147483647
    int MIN_ = 0x80000000;  // -2147483648
public:
    int atoi(const char *str) {

        // valid char for digits are 0-9, +, -
        // 0-9 : 0x30 - 0x39
        // + : 0x2b
        // - : 0x2d

        // rules:
        // str = "123", return 123
        // str = "+123", return 123
        // str = "-123", return -123
        // str = "123ab4", return 123
        // str = "12344566778899900", return MAX
        // str = "ab123", return 0
        // str = "  123", return 123

        int result = 0;
        int c = 0;  // counter for overflow

        // empty or invalid char
        if('\0' == str[0]) {
            return 0;
        }

        // remove spaces
        int i = 0;
        while('\0' != str[i]) {
            if(0x20 == str[i]) i++;
            else break;
        }  // now, all space before digits are removed.

        // see if all are space
        if('\0' == str[i]) {
            return 0;
        }

        // first digit
        bool neg = false;
        if (0x39 < str[i]) return 0;
        else if (0x30 > str[i]) {
            switch(str[i]) {
            case 0x2b:
                // +
                neg = false;
                i++;
                if ( (0x39 < str[i]) || (0x30 > str[i]) ) return 0;
                break;
            case 0x2d:
                // -
                neg = true;
                i++;
                if ( (0x39 < str[i]) || (0x30 > str[i]) ) return 0;
                break;
            default:
                return 0;
            }
        }
       
        // start from i, the first number is a digit now.
        while('\0' != str[i] && 0x39 >= str[i] && 0x30 <= str[i]) {
            
            int d = (int)(str[i] - 0x30);

            // overflow
            if (9 == c) {
                if (result > 214748364 || result < -214748364) {
                    return neg ? MIN_ : MAX_;
                } else {
                    switch(result) {
                    case 214748364:
                        if (d > 7) return MAX_;
                        break;
                    case -214748364:
                        if (d > 8) return MIN_;
                        break;
                    default:
                        break;
                    }
                    
                }
            } else if (c >= 10) return neg ? MIN_ : MAX_;
            
            if (!neg) {
                result = result * 10 + d;
            } else {
                result = result * 10 - d;
            }
            i++;
            c++;
            
        }

        return result;

    }
};


int main() {

    Solution s;

    char *str ="-2147483649";

    int result = s.atoi(str);

    cout << "the string is: " << str << "\nthe number is: " << result << endl;  

    return 0;
}
