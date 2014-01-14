/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Jan 14 12:13:29 2014
 * Modified at:   Tue Jan 14 13:25:11 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   Failed case 11498
 *                Input:	-2147447412
 *                Output:	true
 *                Expected:	false
 *                It seems that the leetcode doesn't consider
 *                negative numbers as a palindrome.
 *                Reverse : if the reversed number and the original one are same.
 *                Length : get the lenght of the integer, compare digit by digit.
 *
 */

#include <iostream>
using namespace std;

class Solution {

private:
#ifdef REVERSE
    
    // int max_ = 0x7fffffff;  // 2147483647
    // int min_ = 0x80000000;  // -2147483648

    int reverse(int x) {
        // when overflow set the result to 0;

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
                    result = 0;
                    break;
                } else if (result == 214748364) {
                    result = (7 > x) ? 0 : result;
                    break;
                } else if (result == -214748364) {
                    result = (-8 < x) ? 0 : result;
                    break;
                }
            }

        }

        return result;

    }
#endif  // REVERSE

#ifdef LENGTH

    int getDigitByIndex(int x, int i) {
        
        for (int j = 0; j < i; ++j) {
            x /= 10;
        }

        return x % 10;
    }

#endif  // LENGTH

public:
    bool isPalindrome(int x) {

#ifdef REVERSE

        // ignore negative numbers
        if (x < 0) return false;
        else {
            int rev = reverse(x);
            return (rev == x) ? true : false;
        }

#endif  // REVERSE

#ifdef LENGTH

        if (x < 0) return false;

        int temp = x;
        int len = 0;
        while (temp) {
            temp /= 10;
            len++;
        }

        // now get the length of x
        // compare digit one by one
        // if extra space allowed, we can simply apply an array
        int i = 0;
        int j = len - 1;
        while (i <= j) {
            if (getDigitByIndex(x,i) != getDigitByIndex(x, j)) return false;
            i++;
            j--;
        }

        return true;


#endif  // LENGTG
        
        
    }
};


int main() {

    Solution s;

    int x = ;

    bool result = s.isPalindrome(x);

    cout << "the input number is : " << x << "\n";
    cout << "it is " << (result ? "" : "not ") << "a palindrome." << endl;

    return 0;
}
