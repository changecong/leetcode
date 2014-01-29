/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Wed Jan 29 11:57:03 2014
 * Modified at:   Wed Jan 29 13:23:28 2014
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

private:

    int listLength(ListNode *head) {

        int len = 0;

        if (NULL == head) return len;
        
        ListNode *node = head;

        len++;

        while(NULL != node->next) {
            len++;
            node = node->next;
        }
        
        return len;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {

#ifdef SLOW
        ListNode *node = head;

        if ( n > listLength(node) || (0 == n)) {
            return head;
        }

        if (n == listLength(node)) {
            return head->next;
        }

        while(n < listLength(node->next)) {
            
            node = node->next;
        }

        // remove the next
        node->next = node->next->next;
        
        return head;
#endif  // SLOW

#ifdef FAST
                
        ListNode *node = head;

        int len = listLength(node);

        if ( n > len || (0 == n)) {
            return head;
        }

        if (n == len) {
            return head->next;
        }

        int pointer = 1;

        while((pointer + n) != len) {
            
            node = node->next;
            pointer++;
        }

        node->next = node->next->next;

        return head;

#endif  // FAST

#ifdef ONE_PASS

        

#endif  // ONE_PASS

    }

    ListNode* genLinkedList(int a[], int len) {

        ListNode* node;
        ListNode* head;

        if (0 == len) {
            return NULL;
        } else {
            node = new ListNode(a[0]);
            head = node;
        }
        
        for (int i = 1; i < len; ++i) {
            
            node->next = new ListNode(a[i]);

            node = node->next;
        }

        return head;
    }

    void displayList(ListNode* head) {

        if (NULL != head) {

            ListNode* node = head;

            while(NULL != node->next) {
                cout << node->val << " ";

                node = node->next;
            }

            cout << node->val;

            cout << endl;
        }
    }
};


int main() {

    Solution s;
    
    int a[4] = {1, 2, 3, 4};

    int n = 2;

    ListNode* head = s.genLinkedList(a, 4);

    ListNode* result = s.removeNthFromEnd(head, n);

    s.displayList(result);

    return 0;
}
