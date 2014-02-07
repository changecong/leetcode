/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Feb  7 12:06:35 2014
 * Modified at:   Fri Feb  7 12:48:53 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        
#ifdef BRUTE_FORCE

        int size = 9;
        bool isValid = true;

        // gen a hash map
        map<char, int> standard;
        standard.insert(make_pair('.', 10));
        standard.insert(make_pair('1', 1));
        standard.insert(make_pair('2', 1));
        standard.insert(make_pair('3', 1));
        standard.insert(make_pair('4', 1));
        standard.insert(make_pair('5', 1));
        standard.insert(make_pair('6', 1));
        standard.insert(make_pair('7', 1));
        standard.insert(make_pair('8', 1));
        standard.insert(make_pair('9', 1));
        

        // check each row
        for(int i = 0; i < size; ++i) {

            if (!isValid) break;
            map<char, int> temp = standard;
            for (int j = 0; j < size; ++j) {
                if (temp[board[i][j]] == 0) {  // exist before;
                    isValid = false;
                    break;
                }
                
                temp[board[i][j]]--;
            }
        }

        if (!isValid) return isValid;
  
        // check each column
        for(int i = 0; i < size; ++i) {

            if (!isValid) break;
            map<char, int> temp = standard;
            for (int j = 0; j < size; ++j) {
                if (temp[board[j][i]] == 0) {  // exist before;
                    isValid = false;
                    break;
                }
                
                temp[board[i][j]]--;
            }
        }

        if (!isValid) return isValid;

        // check each block
        for (int i = 0; i < 3; ++i) {
            if (!isValid) break;
            for (int j = 0; j < 3; ++j) {
                if (!isValid) break;
                map<char, int> temp = standard;
                for (int l = 3*i; l < 3*(i+1); ++l) {
                    if (!isValid) break;
                    for (int m = 3*j; m < 3*(j+1); ++m) {
                        
                        if (temp[board[l][m]] == 0) {  // exist before;
                            isValid = false;
                            break;
                        }
                        
                        temp[board[l][m]]--;
                    }
                }
                
                
            }
        }
        
        return isValid;
        

#endif  // BRUTE_FORCE
    }
};


int main() {

    Solution s;

    /*Too lazy to write a test example*/

    vector<vector<char> > board;

    return 0;
}
