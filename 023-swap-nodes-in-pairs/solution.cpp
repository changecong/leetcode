/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Jan 31 13:37:32 2014
 * Modified at:   Fri Jan 31 15:04:15 2014
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
    ListNode *swapPairs(ListNode *head) {
        
#ifdef REMOVE_INSERT

        ListNode* node = head;
        
        ListNode* temp;
        
        ListNode* prev = NULL;

        while(NULL != node) {

            if (NULL == node->next) break;
            // if (NULL == node->next->next) break;
            
            // save
            ListNode* temp = new ListNode(node->val);
            
            // remove
            if (NULL != prev) {
                prev->next = node->next;
            } else {
                head = node->next;
            }

            node = node->next;
            // add
            temp->next = node->next;
            node->next = temp;

            // move
            prev = node->next;
            node = node->next->next;
            
        }

        return head;

#endif  // REMOVE_ADD
    }

    ListNode* genLinkedList(int a[], int len) {

        ListNode* result;

        if (0 == len) return NULL;

        result = new ListNode(a[0]);
        
        ListNode* node = result;

        for (int i = 1; i < len; ++i) {
            node->next = new ListNode(a[i]);
            node = node->next;
        }

        return result;
        
    }

    void displayLinkedList(ListNode* head) {

        ListNode* node = head;

        while(NULL != node) {
            cout << node->val << "->" ;
            node = node->next;
        }

        cout << "NULL" << endl;
    }
    
};


int main() {

    Solution s;

    int a[6] = {1, 2, 3, 4, 5, 6};

    ListNode* list = s.genLinkedList(a, 0);

    ListNode* result = s.swapPairs(list);

    s.displayLinkedList(result);

    return 0;
}
