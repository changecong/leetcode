/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Wed Jan 29 17:15:55 2014
 * Modified at:   Fri Jan 31 11:01:21 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {

#ifdef RECURSIVE

private:

    ///\ param[in] n : the n
    ///\ param[in] l : used left
    ///\ param[in] r : used right
    vector<string> restParenthesis(int n, int l, int r) {
        
        vector<string> results;

        // complete
        if (r == n ) return results;

        // if all left used
        if (l >= n) {
            string result("");
            // put all unused right in
            for (int i = r; i < n; ++i) {
                result += ")";
            }

            results.push_back(result);
            return results;
        }

        // garentee l < n

        // if not
        if (l == r) { // only l allowed
            
            string temp_str = "(";
            l++;
            vector<string> temp_vec = restParenthesis(n, l, r);
            for (int i = 0; i < temp_vec.size(); ++i) {
                string result = temp_str + temp_vec[i];
                results.push_back(result);
            }
        } else if (l > r) {  // both l and r are allowed
            string temp_str = "(";
            l++;
            vector<string> temp_vec = restParenthesis(n, l, r);
            for (int i = 0; i < temp_vec.size(); ++i) {
                string result = temp_str + temp_vec[i];
                results.push_back(result);
            }
            l--;
            
            temp_str = ")";
            r++;
            temp_vec = restParenthesis(n, l, r);
            for (int i = 0; i < temp_vec.size(); ++i) {
                string result = temp_str + temp_vec[i];
                results.push_back(result);
            }            
        }

        return results;
    }

#endif  // RECURSIVE

public:
    vector<string> generateParenthesis(int n) {

#ifdef RECURSIVE

        vector<string> results;
        int l = 1;
        int r = 0;

        string temp_str = "(";
        vector<string> temp_vec = restParenthesis(n, l, r);
        for (int i = 0; i < temp_vec.size(); ++i) {
            string result = temp_str + temp_vec[i];
            results.push_back(result);
        }

        return results;

#endif  // RECURSIVE
        
      
    }
};


int main() {

    Solution s;
    int n = 3;

    vector<string> results = s.generateParenthesis(n);

    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << " " ;
    }

    cout << endl;

    return 0;
}
