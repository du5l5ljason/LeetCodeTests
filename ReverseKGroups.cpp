//
//  ReverseKGroups.cpp
//  
//
//  Created by 廷芳 杜 on 7/19/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
class Solution {
public:
    void reverse( ListNode *&node, int n )
    {
        if( n == 1 ) return;
        ListNode *next = node->next;
        reverse( next, n-1 );
        ListNode *current = node;
        int len = n-1;
        while( len>0 )
        {
            swap( current->val, current->next->val );
            current = current->next;
            len--;
        }
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( head == NULL )  return NULL;
        if( k == 1 ) return head;
        ListNode *current = head;
        ListNode *nextHead = head;
        
        int i = k;
        while( i > 0 && nextHead!=NULL )
        {
            nextHead = nextHead->next;
            i--;
        }
        if( i == 0 )
        {
            reverse( current, k );
            reverseKGroup( nextHead, k );
        }
        return head;
    }
};