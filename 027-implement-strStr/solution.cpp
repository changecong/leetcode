/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Jan 31 23:49:37 2014
 * Modified at:   Mon Feb  3 11:59:22 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <stdlib.h>     /* malloc, free, rand */
#include <string.h>

using namespace std;

class Solution {

#ifdef KMP

private:
    
    void computePrefixTable(char* p, int len, int t[]) {

        t[0] = 0;

        int j = 0;
        
        for (int i = 1; i < len; ++i) {

            while(j > 0 && p[i] != p[j] ) {
                j = t[j-1];
            }

            if (p[i] == p[j]) {

                j++;
            }

            t[i] = j;
        }

    }


#endif  // KMP

public:
    char *strStr(char *haystack, char *needle) {

#ifdef BRUTE_FORCE

        char* result;

        if('\0' == haystack[0] && '\0' == needle[0]) {
            result = (char*) malloc(1);
            strcpy(result, "");
            return result;
        }

        // get the length of needle
        int len = 0;

        int i = 0;
        int j = 0;
        int ioffset = i;

        while ('\0' != haystack[i]) {
            
            // according to the benchmarks, it seems that when the needle
            // is "", return the haystack. However, by my understanding, null
            // should be returned.
            if('\0' == needle[0]) return haystack;

            ioffset = i;
            j = 0;

            while(haystack[ioffset] == needle[j]) {

                ioffset++;
                j++;
                
                if ('\0' == haystack[ioffset] && '\0' != needle[j]) return NULL;

                // got it
                if ('\0' == needle[j]) {

                    // allocate memory
                    // result = (char*)malloc(j);
                    // strncpy(result, haystack + i, j);
                    // return result;
                    return haystack+i;
                }
            }

            i++;
            
        }


        return NULL;

#endif  // BRUTE_FORCE
  
#ifdef KMP

        char* result;
        
        if('\0' == haystack[0] && '\0' == needle[0]) {
            result = (char*) malloc(1);
            strcpy(result, "");
            return result;
        }

        // get the table
        // get the length

        int len = 0;
        while ('\0' != needle[len++]);
        
        // int *next;
        // next = (int*)malloc(len);
        // memset(next, 0, sizeof(int)*len);
        int next[len];

        computePrefixTable(needle, len-1, next);

        int i = 0;
        int j = 0;
        int offset = i;

        while ('\0' != haystack[i]) {
            
            // according to the benchmarks, it seems that when the needle
            // is "", return the haystack. However, by my understanding, null
            // should be returned.
            if('\0' == needle[0]) return haystack;

            while(haystack[i] == needle[j]) {
                i++;
                j++;

                if ('\0' == haystack[i] && '\0' != needle[j]) return NULL;

                // got it
                if ('\0' == needle[j]) {

                    return haystack + offset;
                }

            }

            // !=
            if (0 == j) {
                i = ++offset;
            } else {
                // check the table
                // j = j - ((j - 1) - next[j-1]);
                j =  next[j-1];
                offset = i - j;
            }

        }

        return NULL;
#endif  // KMP

#ifdef BM

#endif  // BM
    
    }
};


int main() {

    Solution s;

    char* haystack = (char* )malloc(24);
    // strcpy(haystack, "bbc abcdab abcdabcdabde");
    strcpy(haystack, "mississippi");
    char* needle = (char*)malloc(8);
    strcpy(needle, "");

    char* result = s.strStr(haystack, needle);

    cout << "The haystack is: " << haystack << endl;
    cout << "The needle is: " << needle << endl;
    cout << "The result is: " << result << endl;

    return 0;
}
