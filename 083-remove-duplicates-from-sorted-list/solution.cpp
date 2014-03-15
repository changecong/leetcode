/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Mar 14 22:13:32 2014
 * Modified at:   Fri Mar 14 22:39:37 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {

        if (NULL == head) return head;

        ListNode* node = head;

        ListNode* previous = node;

        while (NULL != node->next) {

            if (node->val != node->next->val) {  // change
                
                // everything is ok
                previous->next = node->next;
                node = node->next;
                previous = node;

            } else {  // unchange
                node = node->next;
            }            
        }

        previous->next = node->next;
     
        // delete node;
        
        return head;
    }
};


int main() {

    Solution s;

    int A[2] = {1, 1}; // , 2, 2, 3};
    int n = 2;
    ListNode *head = new ListNode(A[0]);
    ListNode *node = head;

    for (int i = 1; i < n; ++i) {
        node->next = new ListNode(A[i]);
        node = node->next;
    }

    ListNode* result = s.deleteDuplicates(head);
    node = result;
    
    while (NULL != node) {
        
        cout << node->val << " -> ";
        node = node->next;
        
    }

    cout << endl;

    return 0;
}
