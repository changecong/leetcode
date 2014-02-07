/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Feb  7 13:46:08 2014
 * Modified at:   Fri Feb  7 14:55:56 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <string>
#include <iostream>

using namespace std;

class Solution {

private:
    string num2Str(int num) {

        string result;
        string rev = "";

        // reverse
        while(num > 0) {
            
            rev += (num % 10) + '0';
            num /= 10;
        }

        // get the result;
        for(int i = rev.size() - 1; i >= 0; --i) {
            result += rev[i];
        }

        return result;
    }

public:
    string countAndSay(int n) {
        
        string result = "";

        if (0 == n) return result;

        if (1 == n) return "1";

        string temp = countAndSay(n - 1);
        
        // at least one

        char c = temp[0];
        int i = 0;
        int counter = 1;

        while(i < temp.size()) {
            i++;
            if (c == temp[i]) {
                counter++;
            } else {

                result += num2Str(counter);
                result += string(1, c);

                c = temp[i];
                counter = 1;
            }
        }

        return result;

    }
};


int main() {

    Solution s;

    int n = 7;

    cout << "The result is: " << endl;

    for (int i = 1; i <= n; ++i ) {
        cout << s.countAndSay(i) << endl;
    }

    return 0;
}
