/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Feb  9 14:07:07 2014
 * Modified at:   Sun Feb  9 14:52:00 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

class Solution {
private:

    void splitNum(int temp,
                  int &c,  // the carry
                  string &result  // the new result;
        ) {
        
        // no more than two digits
        c = temp / 10;
        result += ((temp % 10) + '0');

    }

    string multiplySimple(string num1, 
                          int num2, 
                          int n  // number of 0s
        ) {
        
        if (num2 == 0) return "0";

        string result;

        int c = 0;
        
        for (int i = num1.size()-1; i >= 0; --i) {
            int temp = (num1[i] - '0') * num2 + c;
            splitNum(temp, c, result);
        }
        
        if (c > 0) result += (c + '0');

        // reverse
        reverse(result.begin(), result.end());

        result += string(n, '0');

        return result;
    }

    string add(string num1, string num2) {

        string a;
        string b;
        if (num1.size() >= num2.size()) {
            a = num1;
            b = num2;
        } else {
            a = num2;
            b = num1;
        }

        string result;
        // a is longer

        int i = a.size() - 1;
        int j = b.size() - 1;
        int c = 0;

        while (j >= 0) {
            int temp = (a[i] - '0') + (b[j] - '0') + c;
            c = temp / 10;
            result += ((temp % 10) + '0');
            i--;
            j--;
        }

        while (i >= 0) {
            int temp = (a[i] - '0') + c;
            c = temp / 10;
            result += ((temp % 10) + '0');
            i--;
        }

        if (c != 0) {
            result += (c + '0');
        }

        // reverse
        reverse(result.begin(), result.end());

        return result;
        
    }

public:
    string multiply(string num1, string num2) {
        
        if ("0" == num1 || "0" == num2) return "0";

        string result = "0";

        for (int i = num2.size() - 1; i >= 0; --i) {
            int num = num2[i] - '0';
            
            string temp = multiplySimple(num1, num, num2.size() - i - 1);

            result = add(result, temp);
        }

        return result;

    }
};


int main() {

    Solution s;

    string num1 = "540";
    string num2 = "13500";

    string result = s.multiply(num1, num2);

    cout << num1 << " x " << num2 << " = " << result << endl;

    return 0;
}
