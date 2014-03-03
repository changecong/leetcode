/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Mar  2 15:40:44 2014
 * Modified at:   Sun Mar  2 19:21:09 2014
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
    bool isNumber(const char *s) {
        
        int i = 0;
        bool result = false;

        int e = 'e' - '0';
        int E = 'E' - '0';
        int dot = '.' - '0';
        int negpos = 0;
        bool sym = true;
        int start = 0;

        map<int, int> symbol;
        symbol.insert(make_pair(e, 0));
        symbol.insert(make_pair(E, 0));
        symbol.insert(make_pair(dot, 0));
        symbol.insert(make_pair(negpos, 0));

        // trim front
        while ('\0' != s[i]) {
            if (' ' == s[i]) {
                if (symbol[negpos] > 0) {
                    return false;
                } else {
                    i++;
                }
            } else if (('.' == s[i] && 
                        ('\0' == s[i+1] || ' ' == s[i+1]
                         || 'e' == s[i+1] || 'E' == s[i+1])) 
                       ||'e' == s[i] || 'E' == s[i]) {  // . or e appears before any digit
                return false;

            } else if ('-' == s[i] || '+' == s[i]) {
                if (symbol[negpos] > 0) {
                    return false;
                } else {
                    i++;
                    symbol[negpos]++;
                }
            } else {
                break;
            }
            
        }

        while ('\0' != s[i]) {

            result = true;

            // check space
            while (' ' == s[i]) {
                if (!sym) return false;
                i++;
                if ('\0' == s[i]) return true;
                else if (' ' != s[i]) return false;
            }

            if (('-' == s[i] || '+' == s[i]) && sym) return false;
            else if ('-' == s[i] || '+' == s[i]) {
                i++;
                if (' ' == s[i] || '\0' == s[i]) return false;
                sym = true;
                continue;
            }

            int num = s[i]  - '0';  // [0, 9]

            // knock-out
            if ((num > 9 || num < 0) && num != e && num != dot && num != E) {
                return false;
            }

            // e could only appear once
            if (num == e || num == E) {
                // check the map
                if (symbol[num] > 0) {
                    return false;
                } else {
                    symbol[num]++;
                    sym = false;
                }
            } else if (num == dot) {
                if (symbol[num] > 0 || !sym || symbol[e] > 0 || symbol[E] > 0) {
                    return false;
                } else {
                    symbol[num]++;
                }
            } else {
                sym = true;
            }   

            i++;
        }

        return result && sym;
    }
};

int main() {

    Solution s;

    const char *str = " 6.5e+";

    bool result = s.isNumber(str);

    cout << str << " is " << (result ? "" : "not ") << "a number" << endl;

    return 0;
}
