/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Mar 10 19:38:22 2014
 * Modified at:   Mon Mar 10 23:45:17 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {

        string result = "";

        if (S.size() < T.size()) return result;

        // hash
        int T_table[256] = {0};
        int found[256] = {0};
        // store T;
        string::iterator it_t = T.begin();
        while (it_t != T.end()) {
            T_table[*it_t]++;
            *it_t++;
        }

        // copy
        // memcpy(dulp, counter, 256*sizeof(int));
        
        int window = 0;
        int head = 0;
        int tail = 0;
        int total = 0;
        
        for (tail = 0; tail < S.size(); ++tail) {

            char c = S[tail];

            if (T_table[c] != 0) {  // valid

                found[c]++;
                if (found[c] <= T_table[c]) {  // total
                    total++;

                    if (total == T.size()) {  // find a window

                        while (head <= tail) {

                            char h = S[head];

                            if (T_table[h] == 0) {                                
                                head++;
                            } else {
                                if (found[h] > T_table[h]) {
                                    head++;
                                    found[h]--;   
                                } else {
                                    // calculate window
                                    window = tail - head + 1;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            // go on
            if(window > 0) break;
        }

        if (tail >= S.size()) return result;

        tail++;
        int temp_head = head;

        // continue
        for (; tail < S.size(); ++tail) {
            char c = S[tail];
            
            if (T_table[c] != 0) {  // valid

                found[c]++;

                while (temp_head <= tail) {

                    char h = S[temp_head];

                    if (T_table[h] == 0) {                                
                        temp_head++;
                    } else {
                        if (found[h] > T_table[h]) {
                            temp_head++;
                            found[h]--;   
                        } else {
                            // calculate window
                            int temp_window = tail - temp_head + 1;
                            if (window > temp_window) {
                                head = temp_head;
                                window = temp_window;
                            }
                            break;
                        }
                    }
                }
            }
        }

        result = S.substr(head, window);
        return result;

    }
};


int main() {

    Solution s;

    string S = "ADOBECODEBANC";
    string T = "ABC";

    string result = s.minWindow(S, T);

    cout << "The result is: " << result << endl;

    return 0;
}
