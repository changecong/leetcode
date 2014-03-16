/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Mar 16 11:04:34 2014
 * Modified at:   Sun Mar 16 16:48:37 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        
#ifdef RECURSIVE

        if (s1.size() != s2.size()) return false;
        int len = s1.size();
        
        if (s1 == s2) return true;

        string temp1 = s1;
        string temp2 = s2;

        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());

        if (temp1 != temp2) return false;

        for (int i = 1; i < len; ++i) {

            string s11 = s1.substr(0, i);  // i
            string s12 = s1.substr(i, len - i);
            string s21_0 = s2.substr(0, i);  // i
            string s22_0 = s2.substr(i, len - i);

            bool scramble_0 = isScramble(s11, s21_0) && isScramble(s12, s22_0);
            
            if (scramble_0) {
                return true;
            } else {
                string s21_1 = s2.substr(0, len - i);
                string s22_1 = s2.substr(len - i, i);  // i
                
                bool scramble_1 = isScramble(s11, s22_1) && isScramble(s12, s21_1);

                if (scramble_1) {
                    return true;
                }
            }
        }

        return false;

#endif  // RECURSIVE
    }
};

int main() {

    Solution s;

    string s1 = "abcdefghijklmnopq";
    string s2 = "efghijklmnopqcadb";

    bool result = s.isScramble(s1, s2);

    cout << s1 << " and " << s2 << " are " << (result ? "" : "not ") << "scramble" << endl;

    return 0;
}
