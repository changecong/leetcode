/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Feb 10 21:50:07 2014
 * Modified at:   Mon Feb 10 23:22:25 2014
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

    void nextIndex(int &i, int &j, int n) {

        int temp_i = i;

        i = j;

        j = n - temp_i - 1;
        
    }

    void rotateSequence(vector<vector<int> > &matrix, 
                        int i, int j, int n) {

        int current = matrix[i][j];
        int len = n - (2 * i);
        // calculate the next index
        for (int order = 0; order < 4; ++order) {
            nextIndex(i, j, n);
            int temp = matrix[i][j];
            matrix[i][j] = current;
            current = temp;
        }

    }

public:
    void rotate(vector<vector<int> > &matrix) {

        if (1 < matrix.size()) {
            
            int n = matrix.size();

            // for each layer
            for(int i = 0; i < n/2; ++i) {
                // for the fisrt n - n elements
                for(int j = i; j < (n - i - 1); ++j) {
                    rotateSequence(matrix, i, j, n);
                }
            }
            
        }

    }
};

void display(vector<vector<int> >matrix) {

    int n = matrix.size();
    
    for (int l = 0; l < n; ++l) {
        for (int m = 0; m < n; ++m) {
            cout << matrix[l][m] << " ";
        }
        cout << endl;
    }

}

int main() {
    
    Solution s;
    vector<vector<int> > matrix;
    int i = 0;
    int n = 3;
    
    for (int l = 0; l < n; ++l) {
        vector<int> temp;
        for (int m = 0; m < n; ++m) {
            temp.push_back(++i);
        }
        matrix.push_back(temp);
    }

    display(matrix);

    s.rotate(matrix);
    
    display(matrix);

    // test nextIndex
    // int i = 0;
    // int j = 1;
    // int n = 4;
    // int order = 0;
    // cout << i << ", " << j << endl;

    // while (order < 4) {
        
    //     s.nextIndex(i, j, n);

    //     cout << i << ", " << j << endl;
        
    //     order++;
    // }

    return 0;
}
