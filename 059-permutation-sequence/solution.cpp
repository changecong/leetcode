/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sat Feb 15 09:34:40 2014
 * Modified at:   Tue Feb 18 22:34:48 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std; 

class Solution {
private:
    int factorial(int n) {
        
        int result = 1;
        
        while(n > 0) {
            result *= n;
            n--;
        }

        return result;
    }

public:
    string getPermutation(int n, int k) {

        string result = "";

        if (n == 0 || k == 0) return result;

        // gen a table
        vector<int> digits;
        for (int i = 0; i <= n; ++i) {
            digits.push_back(i);
        }

        // calculate the k        

        for (int i = 0; i < n; ++i) {
        
            k--;

            int temp = factorial(n - i - 1);

            int index = k / temp + 1;  // section
                                         // |
                                         // 1234 1243 ... 1432
                                         // 2134 2143 ... 2431
                                         // ...
            k = k % temp + 1;

            result += ('0' + digits[index]);
            // remove from the vector
            digits.erase(digits.begin() + index);
        }

        return result;
    }

    int factorialN(int n) {
        return factorial(n);
    }

};


int main() {

    Solution s;

    int n = 4;
    for (int k = 1; k <= s.factorialN(n); ++k) {

        string result = s.getPermutation(n, k);

        cout << "The result is: " << result << endl;
    }

    return 0;
}
