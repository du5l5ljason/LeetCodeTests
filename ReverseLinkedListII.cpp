//
//  ReverseLinkedListII.cpp
//  
//
//  Created by 廷芳 杜 on 7/11/13.
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
    void swap( int &a, int &b )
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void reverseList( ListNode * &node, int length )
    {
        if( length == 1 ) return;
        ListNode *next = node->next;    //if next == NULL, length>1, this is fault.
        reverseList( next, length-1 );
        //switch node and reversed next linked list
        int lenOfList = length-1;
        ListNode *current = next;
        swap( current->val, node->val);
        
        while( lenOfList>1 )
        {
            swap( current->val, current->next->val );
            current = current->next;
            lenOfList--;
        }
        
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( head == NULL ) return NULL;
        ListNode *current = head;
        for( int i=1; i<m; i++ )
            current = current->next;
        int len = n-m+1;
        reverseList( current, len );
        return head;
    }
};