//
//  PartitionLists.cpp
//  
//
//  Created by 廷芳 杜 on 7/9/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

* struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
*/
class Solution {
public:
    void insert( ListNode* &node, int val )
    {
        node->next = new ListNode( val );
        node = node->next;
    }
    
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( head == NULL ) return NULL;
        if( head->next == NULL ) return head;
        
        ListNode *less = NULL;
        ListNode *lessCur = less;
        ListNode *greater = NULL;
        ListNode *greaterCur = greater;
        
        ListNode *current = head;
        
        while( current!=NULL )
        {
            if( current->val < x )
            {
                if( less == NULL )
                {
                    less = new ListNode( current->val );
                    lessCur = less;
                }
                else
                    insert( lessCur, current->val );
            }
            else
            {
                if( greater == NULL )
                {
                    greater = new ListNode( current->val );
                    greaterCur = greater;
                }
                else
                    insert( greaterCur, current->val );
            }
            
            current = current->next;
        }
        
        if( less == NULL )
        {
            current = greater;
            return greater;
        }
        else
        {
            current = less;
            while( current->next!= NULL )
            {
                current = current->next;
            }
            current->next = greater;
            
            return less;
        }
    }
};