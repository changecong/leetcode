/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Feb  9 14:55:08 2014
 * Modified at:   Mon Feb 10 12:32:36 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {

#ifdef FAST

        const char *str = s;
        const char *pat = p;

        for (; *str != '\0'; str++, pat++) {

            switch(*pat) {

            case '\0':
                // end of 
                return false;
                
            case '?':
                break;

            case '*':
                if (isMatch(str, pat + 1)) { // empty
                    return true;
                } else { 
                    // try all
                    while ( )
                    
                }

                break;
                
            default:
                if (*pat == *str) {
                    break;
                } else {
                    return false;
                }       
            }

        }

        if ('\0' == str) {}


#endif  // FAST

#ifdef SLOW      
        // cout << "s : " << s << endl;
        // cout << "p : " << p << endl;

        if ('\0' == s[0]) {
            
            if (p[0] == '\0') return true;
            else if (p[0] != '*') return false;
        }
       
        switch (p[0]) {

        case '\0':
            
            return ('\0' == s[0]) ? true : false;
        
            break;

        case '?':
            
            // match one single charactor
            return isMatch(s + 1, p + 1);

            break;

        case '*':
            // any sequence of characters
            // empty
            if (isMatch(s, p + 1)) {
                return true;
            } else {  // not an empty sequence                

                char c = s[0];
                if (c == '\0') return false;
 
                if (c == s[1]) {
                    if (isMatch(s + 1, p)) { // match more
                        return true; 
                    } else {  // match one
                        return isMatch(s + 1, p + 1);
                    }
                } else {
                    return isMatch(s + 1, p + 1);
                }
            } 

            break;

        default:
            
            if (s[0] == p[0]) {
                return isMatch(s + 1, p + 1);
            } else {
                return false;
            }

        }

#endif  // SLOW

    }
};


int main() {

    Solution s;

    // char str[] = "aaabbbbbc";
    char str[] = "babbaaaaabbbbbaaaabaaaaaabbbbbaabaabaaaabbbbbbbbaaaabaabababaaaaaabaabbababaaabaababaaaababbbbbbbbaaababbbbbbbbbabbabbaaaaabbbabaabbbbabaaabbaabbbabbabbabaababbbaaabbbbbaaaaabbababaaaabaaaababbaaabbba";
    // char p[] = "aaabbbbbb***c*";
    char p[] = "**********bbb*a**a*b**b*a*aba*aa***ba**a*ab**b*****aba*b***a**a*b******a***bb***a**b*******bb*****aaa*a";

    bool result = s.isMatch(str, p);

    cout << "The input string is: " << str << endl;
    cout << "The pattern is: " << p << endl;
    cout << "The result is: " << ((result) ? "true" : "false") << endl;

    return 0;
}
