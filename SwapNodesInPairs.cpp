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
        
        ListNode *helper = new ListNode(0);
        helper->next = head;
        ListNode *current = helper;
        while( current->next!=NULL && current->next->next!=NULL )
        {
            ListNode *next = current->next;
            ListNode *temp = next->next;
            next->next = temp->next;
            temp->next = next;
            current->next = temp;
            
            current = current->next->next;
        }
        return helper->next;
    }
};