/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Feb 13 23:50:39 2014
 * Modified at:   Fri Feb 14 00:40:21 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {

        if('\0' == s[0]) return 0;
        
        int len = 0;
        int temp_len = len;

        int seeker = 0;        
        
        // seek for each word
        while ('\0' != s[seeker]) {
            
            if (' ' != s[seeker]) {  // valid word
                temp_len++;
            } else if (s[seeker - 1] != ' ') {
                len = temp_len;
                temp_len = 0;               
            }

            seeker++;
        }

        len = (temp_len > 0) ? temp_len : len;

        return len;
    }
};


int main() {

    Solution s;

    char str[] = "helloworld  ";

    int result = s.lengthOfLastWord(str);
    
    cout << "The string is: " << str << endl;
    cout << "The lenght of the last word is: " << result << endl;

    return 0;
}
