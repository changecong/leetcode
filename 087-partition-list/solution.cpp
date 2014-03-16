/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Mar 16 16:53:34 2014
 * Modified at:   Sun Mar 16 18:40:38 2014
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
    ListNode *partition(ListNode *head, int x) {

        if (NULL == head) return head;

        ListNode* extra = new ListNode(x+1);
        extra->next = head;

        ListNode* node = extra;
        ListNode* pos = extra;

        bool split = false;

        while (NULL != node->next) {
            
            if (x <= node->next->val) {
                if (!split) {
                    pos = node;
                    split = true;
                }

                node = node->next;
            } else {  // move to the pos
                
                if (pos->next != node->next) {  // if equal, no need to move

                    ListNode* pos_next = pos->next;
                    ListNode* node_2_next = node->next->next;

                    pos->next = node->next;  // link pos and node next;

                    pos = pos->next;  // move forward pos

                    pos->next = pos_next;  // link to the post next

                    node->next = node_2_next;  // link the gap
                } else {

                    node = node->next;
                    pos = node;
                }
            }
        }

        return extra->next;
    }
};


int main() {

    Solution s;

    int A[6] = {2, 1, 3, 2, 5, 2};

    ListNode* head = new ListNode(A[0]);

    ListNode* node = head;

    for (int i = 1; i < 2; ++i) {

        node->next = new ListNode(A[i]);
        node = node->next;
    }

    int x = 2;

    ListNode *result = s.partition(head, x);

    while (result != NULL) {
        
        cout << result->val << " -> ";
        result = result->next;
        
    }

    cout << endl;

    return 0;
}
