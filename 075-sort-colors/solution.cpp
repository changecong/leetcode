/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Mar 10 12:56:37 2014
 * Modified at:   Mon Mar 10 13:42:52 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
 
#ifdef COUNTING

        int counter[3] = {0};

        for(int i = 0; i < n; i++) {
            counter[A[i]]++;
        }

        int index = 0;
        for(int i = 0; i < 3; i++) {
            while(counter[i] > 0) {
                
                A[index] = i;
                counter[i]--;
                index++;
            }
        }

#endif  // COUNTING
       
#ifdef ONE_PASS

        // two pointers
        int head = 0;
        int tail = n - 1;
        int index = 0;


        while (head <= tail && index <= tail) {
            
            switch(A[index]) {

            case 0:  // switch with the head
                A[index] = A[head];
                A[head] = 0;
                head++;
                index++;
                break;
            case 1:  // do not move until the first 0;
                index++;
                break;
            case 2:  // switch with the tail
                A[index] = A[tail];
                A[tail] = 2;
                tail--;
                break;
            default:
                break;
            }

        }

#endif  // ONE_PASS

    }
};


int main() {

    Solution s;

    int A[18] = {0, 1, 1, 1, 0, 0, 1, 2, 1, 2, 2, 2, 0, 0, 0, 1, 1, 1};
    int n = 18;

    s.sortColors(A, n);

    for (int i = 0; i < n; ++i) {
        cout << A[i] << ", ";
    }

    cout << endl;

    return 0;
}
