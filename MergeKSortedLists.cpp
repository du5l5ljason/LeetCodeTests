//
//  MergeKSortedLists.cpp
//  
//
//  Created by 廷芳 杜 on 4/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( lists.size() == 0 ) return NULL;
        if( lists.size() == 1 ) return lists[0];
        
        int len = lists.size();
        vector<ListNode*> list1;
        vector<ListNode*> list2;
        for( int i = 0 ; i< len ; i++ )
        {
            if( i < len/2 )
            {
                list1.push_back( lists[i] );
            }
            else
            {
                list2.push_back( lists[i] );
            }
        }
        ListNode *listHead1 = NULL;
        ListNode *listHead2 = NULL;
        
        listHead1 = mergeKLists( list1 );
        listHead2 = mergeKLists( list2 );
        
        ListNode* result=mergeTwoLists( listHead1, listHead2 );
        
        return result;
    }
    
    ListNode* mergeTwoLists( ListNode* node1, ListNode* node2 )
    {
        if( node1 == NULL && node2 == NULL ) return NULL;
        if( node1 == NULL ) return node2;
        else if( node2 == NULL ) return node1;
        else
        {
            ListNode *result = NULL;
            if( node1->val < node2->val )
            {
                result = node1;
                result->next = mergeTwoLists( node1->next, node2 );
            }    
            else
            {
                result = node2;
                result->next = mergeTwoLists( node1, node2->next );
            }
            
            return result;
        }
    }
    
};