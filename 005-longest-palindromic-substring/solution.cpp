/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Jan 13 12:35:36 2014
 * Modified at:   Mon Jan 13 13:57:47 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

using namespace std;

class Solution {

private:

#ifdef BRUTE_FORCE
    void palindromeFromCenter(string s, int i, int& l, int& r, int &max) {        
         
        int l_odd, r_odd, l_even, r_even;
        int max_odd, max_even;   

        // check odd abcba
        l_odd = r_odd = i;
        while (l_odd > 0 && r_odd < s.size()-1) {
            if (s[l_odd - 1] == s[r_odd + 1]) {
                l_odd--;
                r_odd++;
            } else break;
        }
        
        max_odd = r_odd - l_odd + 1;

        // check even abba
        if ((i < s.size()) && (s[i] == s[i+1])) {
            l_even = i;
            r_even = i+1;
            while (l_even > 0 && r_even < s.size()-1) {
                if (s[l_even - 1] == s[r_even + 1]) {
                    l_even--;
                    r_even++;
                } else break;
            }

            max_even = r_even - l_even + 1;
            
        } else {
            max_even = 0;
        }

        if (max_odd >= max_even) {
            max = max_odd;
            l = l_odd;
            r = r_odd;
        } else {
            max = max_even;
            l = l_even;
            r = r_even;
        }        
    }

#endif  // BRUTE_FROCE


public:
    string longestPalindrome(string s) {

#ifdef BRUTE_FORCE

        if (s.size() == 0) return "";
        if (s.size() == 1) return s;

        int l = 0;
        int r = 0;
        int max = 0;

        for (int i = 0; i < s.size(); ++i) {
            int temp_m = 0;
            int temp_l = 0;
            int temp_r = 0;
            palindromeFromCenter(s, i, temp_l, temp_r, temp_m);
            if (temp_m > max) {
                max = temp_m;
                l = temp_l;
                r = temp_r;
            }
        }

        return s.substr(l, max);

#endif  // BRUTE_FORCE

// #ifdef DP

//         // ASSUME the maximum lenght of string is 1000
//         // the table looks like
//         // 1 0 0 0 ... 0
//         // 0 1 0 0 ... 0
//         // 0 0 1 0 ... 0
//         // 0 0 0 1 ... 0
//         //      ...
//         // 0 0 0 0 ... 1
            
//         bool index[1000][1000] = {false};
//         for (int i = 0; i < 1000; ++i) {
//             index[i][i] = true;
//         }

//         // looking for the smallest unit
//         for (int i = 0; i < s.size(); ++i) {
//             if (s[i] == s[i+1]) {
//                 index[i][i+1] = true;
//             }
//         }

// #endif  // DP
            }
};


int main() {

    Solution s;

    string str = "eeeee";
    string result = s.longestPalindrome(str);

    cout << "the longest palindromic substring is: " << result << endl;

    return 0;
}
