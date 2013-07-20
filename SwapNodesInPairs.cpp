//
//  SwapNodesInPairs.cpp
//  
//
//  Created by 廷芳 杜 on 7/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( head == NULL ) return NULL;
        if( head->next == NULL ) return head;
        ListNode *node1 = head;
        ListNode *node2 = head->next;
        ListNode *nextHead = node2->next;
        ListNode *temp = new ListNode(0);           //swap node1 and node2
        node2->next = temp;
        temp->next = node1;
        node1->next = swapPairs( nextHead );
        node2->next = temp->next;
        delete temp;
        return node2;
    }
};