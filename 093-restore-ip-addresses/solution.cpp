/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Mar 17 21:26:34 2014
 * Modified at:   Tue Mar 18 21:40:03 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> restoreIpAddresses(string s, int n) {
       
        vector<string> result;
        
        // return null
        if (s.empty() || s.size() > (3*n + 1) || n == 0) return result;  

        if (s[0] == 'E') return result;

        int num = 0;
        for(int i = 0; i < 3 && i < s.size() - 1; ++i) {
            
            num = num * 10 + (s[i] - '0');  

            if (num > 255) break;
            
            // get the rest
            vector<string> temp_result = restoreIpAddresses(s.substr(i+1), n - 1);

            if (!temp_result.empty()) {
                for (int j = 0; j < temp_result.size(); ++j) {
                    result.push_back(s.substr(0, i + 1) + "." + temp_result[j]);
                }
            } else if (s[i + 1] == 'E' && n == 1) {  // last section
                result.push_back(s.substr(0, i + 1));
            }

            if ( num == 0 ) break;  // '0' could only appears in the first digit

        }
        
        

        return result;
    }

public:
    vector<string> restoreIpAddresses(string s) {

        s += 'E';  // used to mark the end of string avoid overflow
        return restoreIpAddresses(s, 4);

    }
};



int main() {

    Solution s;

    string str = "01000";

    vector<string> result = s.restoreIpAddresses(str);

    for (int i = 0; i < result.size(); ++i) {
        
        cout << result[i] << endl;
    }

    return 0;
}
