/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Mar 16 19:29:59 2014
 * Modified at:   Mon Mar 17 11:28:28 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {

#ifdef RECURSIVE
        if (s.empty()) return 0;
        if (1 == s.size()) return 1;
        if (2 == s.size()) {
            int num = (s[0] - '0') * 10 + (s[1] - '0');
            if (num == 10 || num == 20) return 1;
            if (num < 25) return 2;
            return 1;
        }

        if (s[0] == '0') return 0;

        if (s[0] == '1') {

            if (s[1] == '0') {  // 10 only
                return numDecodings(s.substr(2));
            } else {
                return numDecodings(s.substr(1)) + numDecodings(s.substr(2));
            }            
            
        } else if (s[0] == '2') {
            if (s[1] == '0') {
                return numDecodings(s.substr(2));
            } else if (s[1] - '0' <= 6) {
                return numDecodings(s.substr(1)) + numDecodings(s.substr(2));
            } else {
                return numDecodings(s.substr(1));
            }
        } else {
            return numDecodings(s.substr(1));
        }       

#endif  // RECURSIVE

#ifdef DP

        if (s.empty() || s[0] == '0') return 0;
        int cur_2 = 1;
        int cur_1 = 1;
        int cur = 0;

        for (int i = 2; i <= s.size(); ++i) {
            if (s[i - 1] != '0') cur += cur_1;
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) cur += cur_2;
            
            cur_2 = cur_1;
            cur_1 = cur;
            cur = 0;

        }
        
        return cur_1;
        

#endif  // DP
    }
};


int main() {

    Solution s;

    string str = "8299152987184352183335613793611738246622952882892165423687431814339833963464637792247791375416898193";

    int result = s.numDecodings(str);

    cout << "There is(are) " << result << " way(s)." << endl;

    return 0;
}
