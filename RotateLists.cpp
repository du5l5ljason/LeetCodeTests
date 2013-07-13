//
//  RotateLists.cpp
//  
//
//  Created by 廷芳 杜 on 7/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

* Definition for singly-linked list.
* struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
*/
class Solution {
public:
    int getLength( ListNode *head )
    {
        if(head == NULL ) return 0;
        int counter = 0 ;
        while( head!=NULL )
        {
            head = head->next;
            counter++;
        }
        return counter;
    }
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( head == NULL) return NULL;
        ListNode *post = head;
        ListNode *pre = head;
        
        int len = getLength( head );
        int offset = k%len;
        if( offset == 0 ) return head;
        
        for(int i = 0 ; i< offset ; i++ )
        {
            post = post->next;
            if( post == NULL ) return head;
        }
        while( post!=NULL)
        {
            post = post->next;
            pre = pre->next;
        }
        ListNode *current = head;
        
        for( int i = 1 ; i < offset ; i++ )
        {
            swap( pre->val, current->val);
            pre = pre->next;
            current = current->next;
        }
        swap( pre->val, current->val );
        current->next = rotateRight( current->next, offset );
        
        return head;
        
    }
};