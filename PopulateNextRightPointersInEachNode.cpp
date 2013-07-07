//
//  PopulateNextRightPointersInEachNode.cpp
//  
//
//  Created by 廷芳 杜 on 7/5/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( root == NULL ) return;
        
        if( root->left )
        {
            root->left->next = root->right;
            connect( root->left );
        }   
        if( root->right )
        {
            if(root->next)
                root->right->next = root->next->left;
            else
                root->right->next = NULL;
            
            connect( root->right );
        }
    }
};