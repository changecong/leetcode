/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Mar  9 21:21:07 2014
 * Modified at:   Sun Mar  9 21:56:27 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   This is a edit distance problem. could be solved by DP
 *
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {

private:

    int min(int a, int b, int c) {

        int temp = (a > b) ? b : a;

        return (temp > c) ? c : temp;
        
    }

public:
    int minDistance(string word1, string word2) {
        
/*
  d('', '') = 0               -- '' = empty string
  d(s, '')  = d('', s) = |s|  -- i.e. length of s
  d(s1+ch1, s2+ch2)
  = min( d(s1, s2) + if ch1=ch2 then 0 else 1 fi,
    d(s1+ch1, s2) + 1,
    d(s1, s2+ch2) + 1 )
*/ 
    
        if(word1.empty() || word2.empty()) return 0;
        
        int rows = word1.size() + 1;  // from empty string
        int cols = word2.size() + 1;  // from empty string
        
        // define a 2-d array
        vector<vector<int> > table;
        vector<int> temp(cols, 0);
        for (int i = 0; i < rows; ++i) {
            table.push_back(temp);
        }

        table[0][0];  // d('','') = 0
        for(int i = 1; i < cols; ++i) table[0][i] = i;  // d('', s) = |s|
        for(int i = 1; i < rows; ++i) table[i][0] = i;  // d(s, '') = |s|

        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {

                int replace = table[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1);
                int del     = table[i][j-1] + 1;
                int insert  = table[i-1][j] + 1;

                table[i][j] = min(replace, del, insert);

            }
        }
        
        return table[rows-1][cols-1];        

    }
};


int main() {

    Solution s;

    string word1 = "good good study";
    string word2 = "day day up";

    int result = s.minDistance(word1, word2);

    cout << "The minimum distance is: " << result << endl;

    return 0;
}
