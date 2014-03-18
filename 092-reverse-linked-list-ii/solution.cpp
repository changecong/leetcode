/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Mar 17 20:28:21 2014
 * Modified at:   Mon Mar 17 21:21:52 2014
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        
        if (NULL == head || m == n) return head;

        // Given m, n satisfy the following condition:
        // 1 ≤ m ≤ n ≤ length of list.

        // gen an extra node
        ListNode* extra = new ListNode(0);
        extra->next = head;

        ListNode* node_m = extra;
        ListNode* node_n = extra;
        ListNode* previous = extra;

        // find the mth node
        for (int i = 0; i < m; ++i) {
            previous = node_m;
            node_m = node_m->next;
        }
        
        // find the nth node
        for (int i = 0; i < n; ++i) {
            node_n = node_n->next;
        }

        // switch
        while (node_m != node_n) {
            
            // put node_m to the next of node_n

            previous->next = node_m->next;  // skip node_m

            node_m->next = node_n->next;  // insert node_m between node_n and its next

            node_n->next = node_m;  // link node_m and node_n;

            node_m = previous->next;  // new node_m
        }


        return extra->next;
    }
};


int main() {

    Solution s;

    int A[5] = {1, 2, 3, 4, 5};
    
    ListNode *head = new ListNode(A[0]);
    ListNode *node = head;

    for (int i = 1; i < 5; ++i) {

        node->next = new ListNode(A[i]);
        node = node->next;
        
    }

    int m = 2;
    int n = 4;

    ListNode *result = s.reverseBetween(head, m, n);
    
    node = result;

    while(NULL != node) {
        cout << node->val << " -> ";
        node = node->next;
    }

    cout << endl;

    return 0;
}
