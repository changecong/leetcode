/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Feb 20 14:47:56 2014
 * Modified at:   Sun Mar  2 15:36:28 2014
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
    string addBinary(string a, string b) {

        // boundary condition
        if (a.empty()) return b;
        if (b.empty()) return a;

        // the result
        string result = "";
        
        string num0 = "";  // long one
        string num1 = "";  // short one

        if (a.size() > b.size()) {
            num0 = a;
            num1 = b;
        } else {
            num0 = b;
            num1 = a;
        }

        // reverse
        reverse(num0.begin(), num0.end());
        reverse(num1.begin(), num1.end());
        int carry = 0;

        string::iterator it0 = num0.begin();
        string::iterator it1 = num1.begin();
        while (it1 != num1.end()) {
            int addend0 = (*it0) - '0';
            int addend1 = (*it1) - '0';
            
            int sum = addend0 + addend1 + carry;
            int digit = sum % 2;
            carry = sum / 2;
            
            // add it to the result;
            result += (digit + '0');
            it0++;
            it1++;
        }

        // the rest
        while (it0 != num0.end()) {
            int addend = (*it0) - '0';
            int sum = addend + carry;
            int digit = sum % 2;
            carry = sum / 2;
            result += (digit + '0');
            it0++;
        }

        // carry
        if (carry > 0) {
            result += (carry + '0');
        }

        // reverse result;
        reverse(result.begin(), result.end());

        return result;        
    }
};

int main() {

    Solution s;

    string a = "100";
    string b = "101";

    string result = s.addBinary(a, b);

    cout << a << " + " << b << " = "<< result << endl;

    return 0;
}


