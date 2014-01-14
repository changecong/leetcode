/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Jan  7 12:22:19 2014
 * Modified at:   Mon Jan 13 11:06:13 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   Longest substring without repeating characters.   
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {

private:
    int MAX(int a, int b) {
        return (a > b ) ? a : b;
    }

    

public:
    int lengthOfLongestSubstring(string s) {        

#ifdef TWO_POINTERS
        // ASSUME a-z & A-Z
        const int NOTEXIST = -1;  // flag

        int head = 0;
        int tail = 0;
        int max = 0;
        
        // initial indices
        int exist[256];
        for (int i = 0; i < 256; ++i) {
            exist[i] = NOTEXIST;
        }
        exist[s[head]] = head;

        while(head < s.size() && tail < s.size()) {
            
            head++;
            if (head == s.size() ) {
                max = MAX(max, head - tail);
                break;
            }


            if (exist[s[head]] != NOTEXIST) {
                max = MAX(max, head - tail);

                // skip to the right position
                tail = (tail <= exist[s[head]]) ? exist[s[head]] + 1 : tail;
            }

            exist[s[head]] = head;
        }

        return max;        

#endif  // TWO_POINTERS

    }
};


int main() {

    Solution s;
    
    string str = "abcdefabcabbb";

    int max = s.lengthOfLongestSubstring(str);

    cout << "The maximum length is: " << max << endl;

    return 0;
}
