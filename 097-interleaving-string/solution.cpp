/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Wed Mar 19 15:21:25 2014
 * Modified at:   Thu Mar 20 13:32:57 2014
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
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        // do it with dp
        // cols are for S1, rows are for S2
        
        if (s1.size() + s2.size() != s3.size()) return false;

        // gen a match matrix
        vector<vector<bool> > match(s1.size() + 1, vector<bool>(s2.size() + 1, false));

        // initialize
        match[0][0] = true;
        // j = 0
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s3[i]) match[i + 1][0] = match[i][0];  // true
            else break;
        }

        // i = 0
        for (int j = 0; j < s2.size(); ++j) {
            if (s2[j] == s3[j]) match[0][j + 1] = match[0][j];  // true
            else break;
        }

        // the rest
        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                
                match[i][j] = (s1[i - 1] == s3[i + j - 1] && match[i - 1][j]) ||
                    (s2[j - 1] == s3[i + j - 1] && match[i][j - 1]);

            }
        }
        
        return match[s1.size()][s2.size()];

    }
};


int main() {

    Solution s;

    string s1 = "aabcc";
    string s2 = "dbbca";

    string s3 = "aadbbcbcac";

    bool result = s.isInterleave(s1, s2, s3);

    cout << "s3 is " << (result ? "" : "not ") << "a interleaving" << endl;

    return 0;
}
