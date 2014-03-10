/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Mar  9 12:27:37 2014
 * Modified at:   Sun Mar  9 21:14:49 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <string>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
     
#ifdef STACK

        string result;

        if (path.empty()) return result;

        stack<string> directories;

        // . currnt
        // . previous
        string::iterator it = path.begin();
        
        while (it != path.end()) {

            while (*it == '/' && it != path.end()) {
                it++;
            }
            string directory;

            while (*it != '/' && it != path.end()) {
                
                directory += *it;
                it++;
                
            }
            
            if (directory == ".") {  // current
                continue;
            } else if (directory == "..") {  // previous
                // pop the stack
                if(!directories.empty()) directories.pop();
            } else if (!directory.empty()) {
                // push the stack
                directories.push(directory);
            }
            
            
        }

        


        if (directories.empty()) {
            return "/";
        } else {

            // reverse the stack
            stack<string> reverse;
            while (!directories.empty()) {
                
                reverse.push(directories.top());
                directories.pop();
            }

            while(!reverse.empty()) {
                result += '/';
                result += reverse.top();
                reverse.pop();
            }

        }

        return result;
        

#endif  // STACK
   
    }
};


int main() {

    Solution s;

    string path = "/a/./b/../../../c/";

    string result = s.simplifyPath(path);

    cout << "The path is: " << result << endl;

    return 0;
}
