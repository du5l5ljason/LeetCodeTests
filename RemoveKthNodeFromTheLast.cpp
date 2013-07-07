//
//  RemoveKthNodeFromTheLast.cpp
//  
//
//  Created by 廷芳 杜 on 7/7/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( head == NULL ) return NULL;
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        for( int i = 0 ; i < n ; i++ )
        {
            fast = fast->next;
        }
        if( fast == NULL ) 
        {
            head = head->next;
            return head;
        }
        while( fast->next!=NULL )
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *next = slow->next;
        slow->next = next->next;
        
        
        return head;
    }
};