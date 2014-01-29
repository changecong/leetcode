/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Wed Jan 29 13:29:41 2014
 * Modified at:   Wed Jan 29 14:13:59 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <stack>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

#ifdef STACK

        map<char, int> mapping;
        mapping.insert(pair<char, int>('(', 1));
        mapping.insert(pair<char, int>(')', -1));
        mapping.insert(pair<char, int>('[', 2));
        mapping.insert(pair<char, int>(']', -2));
        mapping.insert(pair<char, int>('{', 3));
        mapping.insert(pair<char, int>('}', -3));

        if(s.empty()) return true;
        if(1 == s.size()%2) return false;

        stack<char> left;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[') {
                // push
                left.push(c);
            } else {
                // compare with the stack
                if (left.empty()) return false;

                if (mapping.find(c)->second + mapping.find(left.top())->second == 0) {
                    // pop
                    left.pop();
                } else {
                    return false;
                }
            }
        }



        return left.empty() ? true : false;

#endif  // STACK
        
    }
};


int main() {

    Solution s;

    string str = "(({})())";

    bool result = s.isValid(str);

    cout << "The input is: " << str << endl;
    cout << "The result is: " << (result ? "True" : "False") << endl;

    return 0;
}
