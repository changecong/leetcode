/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Wed Mar 26 15:26:15 2014
 * Modified at:   Thu Mar 27 22:43:44 2014
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
public:
    int numDistinct(string S, string T) {

/*
            r a b b b i t
            -------------
          1 1 1 1 1 1 1 1
        r|0 1 1 1 1 1 1 1
        a|0 0 1 1 1 1 1 1
        b|0 0 0 1 2 3 3 3
        b|0 0 0 0 1 3 3 3 
        i|0 0 0 0 0 0 3 3
        t|0 0 0 0 0 0 0 3
*/

        vector<vector<int> >match(T.size()+1, vector<int>(S.size() + 1, 0));

        // initial
        match[0][0] = 1;

        // first row
        for (int i = 1; i <= S.size(); ++i) {
            match[0][i] = 1;
        }

        // first col
        for (int i = 1; i <= T.size(); ++i) {
            match[i][0] = 0;
        }

        // dp
        for (int i = 1; i <= T.size(); ++i) {

            for (int j = 1; j <= S.size(); ++j) {
                
                // first i target matches first j source
                match[i][j] = match[i][j - 1] + (S[j - 1] == T[i - 1] ? match[i - 1][j - 1] : 0);
            }
        }
        

        return match[T.size()][S.size()];

    }
};


int main() {

    Solution s;

    string S = "rabbbit";
    string T = "rabbit";

    int result = s.numDistinct(S, T);

    cout << "The result is: " << result << endl;

    return 0;
}
