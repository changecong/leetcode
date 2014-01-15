/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Jan 14 13:28:10 2014
 * Modified at:   Wed Jan 15 12:22:19 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   Some examples:
 *                isMatch("aa","a") → false
 *                isMatch("aa","aa") → true
 *                isMatch("aaa","aa") → false
 *                isMatch("aa", "a*") → true
 *                isMatch("aa", ".*") → true
 *                isMatch("ab", ".*") → true
 *                isMatch("aab", "c*a*b") → true
 *                Q: will the input contains '.' & '*'?
 *                A: Assume not.
 *
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {

        // consider from p
        // '' only match ''
        if ('\0' == *p) return '\0' == *s;

        // '.*' and 'a*'
        if ('*' == *(p+1)) {
            while (*s == *p || ('.' == *p && '\0' != *s)) {

                // recursive to judge if the tail is match
                // "aaa", "a*c"
                if (isMatch(s, p+2)) {
                    return true;
                }

                s++;
            } 
            
            // move to the next
            return isMatch(s, p+2);

        } else {  // '.' or 'a'

            if (*s == *p || ('.' == *p && '\0' != *s)) {
                return isMatch(s+1, p+1);
            }

            return false;
        }
    }
};


int main() {

    Solution sol;
    
    const char* s = "bbbba";
    const char* p = ".*a*a";

    bool result = sol.isMatch(s, p);

    cout << "Input : " << s << endl;
    cout << "Pattern : " << p << endl;
    cout << (result ? "Match" : "Not match") << endl; 

    return 0;
}
