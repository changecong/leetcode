/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Mar 14 22:44:14 2014
 * Modified at:   Sat Mar 15 00:07:40 2014
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

        ListNode *node = head;
        ListNode *previous = node;

        while (NULL != node->next) {

            if (node == head && node->val == node->next->val) {  // remove all duplcate head

                while (NULL != head->next) {

                    if (head->val == head->next->val) {
                        head = head->next;
                    } else {
                        break;
                    }
                }

                head = head->next;
                if (NULL == head) return head;
                node = head;
                previous = node;

                continue;
            } 

            if (node->val != node->next->val) {
                
                previous = node;
                node = node->next;

            } else {
                
                while (NULL != node->next) {

                    if (node->val == node->next->val) {
                        node = node->next;
                    } else {
                        break;
                    }
                }

                previous->next = node->next;
                node = node->next;
                if (NULL == node) return head;

            }
        }
        node = node->next;

        return head;
    }
};


int main() {

    Solution s;

    int A[3] = {1, 3, 3};
    int n = 3;
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


}
