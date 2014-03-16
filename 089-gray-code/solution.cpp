/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Mar 16 19:07:39 2014
 * Modified at:   Sun Mar 16 19:25:51 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int> result;
        if (0 == n) {
            result.push_back(0);
            return result;
        }
        // for others

        result = grayCode(n - 1);

        int len = result.size();
        int add = 0x1 << (n - 1);
        for (int i = len - 1; i >= 0; --i) {
            result.push_back(result[i] + add);
        }
        
        return result;
    }
};

int main() {

    Solution s;

    int n = 2;

    vector<int> result = s.grayCode(n);

    cout << "[" << endl;

    for (int i = 0; i < result.size(); ++i) {

        cout << "\t" << result[i] << endl;
    }

    cout << "]" << endl;


    return 0;
}
