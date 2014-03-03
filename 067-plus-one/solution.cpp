/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Mar  2 19:27:53 2014
 * Modified at:   Sun Mar  2 19:57:55 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        
        vector<int> result = digits;
        // boundary condition
        if (digits.empty()) return result;

        if (digits.back() != 9) {
            result.back()++;
            return result;
        } else {  // 9
            
            int carry = 1;
            int i = result.size() - 1;

            while (i >= 0) {
                if (result[i] == 9) {
                    result[i] = 0;
                    i--;
                } else {
                    result[i]++;
                    carry = 0;
                    break;
                }
            }

            if (carry == 1) {  // to the first
                result.insert(result.begin(), carry);
            }

        }
        
        return result;
    }
};


int main() {

    Solution s;

    vector<int> digits;
    // digits.push_back(8);
    // digits.push_back(9);

    vector<int> result = s.plusOne(digits);

    for (int i = 0; i < digits.size(); ++i) {
        
        cout << digits[i];
    }
    cout << endl;

    cout << "+ 1\n" << "---------------" << endl;

    for (int i = 0; i < result.size(); ++i) {

        cout << result[i];
    }
    cout << endl;
    
    return 0;
}
