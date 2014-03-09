/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Mar  2 20:03:50 2014
 * Modified at:   Sun Mar  9 00:11:26 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   Assume L is always longer than any word's size
 *
 */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        
#ifdef GREEDY

        vector<string> result;

        if (words.empty()) return result;

        vector<string>::iterator it = words.begin();

        int len = 0;
        vector<string> temp;

        while(it != words.end()) {
            
            // count the length
            if ((len + it->size()) <= L) {  // still have spaces
                
                // add to temp
                temp.push_back(*it);
                len += it->size();

                if (len == L) {  // perfect fit
                    
                    string newline; 
                    vector<string>::iterator it_temp = temp.begin();
                    
                    // construct
                    while(it_temp != temp.end()) {
                        newline += *it_temp;
                        if (it_temp+1 != temp.end()) {
                            newline += ' ';
                        }
                        it_temp++;
                    }

                    result.push_back(newline);  // a newline
                    // clean up
                    temp.clear();
                    len = -1;
                } 

                len++; // space
                it++;

            } else {  // no enough spaces, relocate spaces
                len--;
                int rest = L - len;  // the last space
                
                // put space into intravels one by one
               
                int average = (temp.size() > 1) ? rest / (temp.size() - 1) : rest - 1;
               

                int other = (temp.size() > 1) ? rest % (temp.size() - 1) : 0;
                

                vector<string>::iterator it_temp = temp.begin();

                string newline;
                
                while(it_temp != temp.end()) {                  
                    
                    newline += (*it_temp);
                    
                    if(it_temp + 1 != temp.end() || it_temp == temp.begin()) {

                        if (other > 0) {
                            newline += string((average+2), ' ');
                            other--;
                        } else {
                            newline += string(average+1, ' ');
                        }
                    }

                    it_temp++;
                }

                result.push_back(newline);
                // clean up
                temp.clear();
                len = 0;

                // no need to increase the iterator
                // the corresponding item would be the first one of the next line
            }
        }

        if (!temp.empty()) { // last line
            /*For the last line of text, it should be left justified
              and no extra space is inserted between words.*/

            len--;
            int rest = L - len;  // the last space

            vector<string>::iterator it_temp = temp.begin();

            string newline;
                
            while(it_temp != temp.end()) {                  
                    
                newline += (*it_temp);
                    
                if(it_temp + 1 != temp.end()) {

                    newline += ' ';
                    
                } else {
                    newline += string(rest, ' ');
                }

                it_temp++;
            }

            result.push_back(newline);
            // clean up
            temp.clear();
            len = 0;

        }

        return result;

#endif  // GREEDY

    }
};


int main() {

    Solution s;

    vector<string> words;
    // ["Listen","to","many,","speak","to","a","few."], 6
    words.push_back("Listen");
    words.push_back("to");
    words.push_back("many");
    words.push_back("speak");
    words.push_back("to");
    words.push_back("a");
    words.push_back("few");
    // words.push_back("world");
    // words.push_back("!");

    int L = 6;

    vector<string> result = s.fullJustify(words, L);

    vector<string>::iterator it = result.begin();

    while(it != result.end()) {
        cout << (*it) << endl;
        it++;
    }
    

    return 0;
}
