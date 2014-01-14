/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Jan 14 09:31:02 2014
 * Modified at:   Tue Jan 14 10:16:07 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   Simple : reverse the number by math formula.
 *                Overflow : consider the overflow condition.
 *
 */

#include <iostream>
using namespace std;

class Solution {
private:
    int max_ = 0x7fffffff;  // 2147483647
    int min_ = 0x80000000;  // -2147483648
public:
    int reverse(int x) {
#ifdef SIMPLE
        
        int result = 0;

        while(x) {

            result = (result * 10) + (x % 10);

            x /= 10;

        }

        return result;


#endif  // SIMPLE

#ifdef OVERFLOW

        int result = 0;
        int c = 0;

        while(x) {

            result = (result * 10) + (x % 10);

            x /= 10;
            
            // digits counter add one;
            c++;

            // if the counter is 9;
            if (9 == c) {
                if ( result > 214748364 || result < -214748364 ) {
                    result = (result > 0) ? max_ : min_;
                    break;
                } else if (result == 214748364) {
                    result = (7 > x) ? max_ : result;
                    break;
                } else if (result == -214748364) {
                    result = (-8 < x) ? max_ : result;
                    break;
                }
            }

        }

        return result;


#endif  // OVERFLOW
    }

    int max() {
        return max_;
    }

    int min() {
        return min_;
    }
};


int main() {

    Solution s;
    
    int x = -1000000003;
    
    int result = s.reverse(x);

    cout << "The reversed number is: " << result << endl;

    return 0;
}
