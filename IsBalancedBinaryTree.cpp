//
//  IsBalancedBinaryTree.cpp
//  
//
//  Created by 廷芳 杜 on 4/3/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int getHeight( TreeNode *root )
    {
        if( root == NULL ) return 0;
        if( root->left == NULL && root->right == NULL ) return 1;
        else
            return 1+ max( getHeight( root->left ), getHeight( root->right ) );
    }
    
    
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( root == NULL ) return true;
        if( root->left == NULL && root->right == NULL ) return true;
        
        if( isBalanced( root->left ) && isBalanced ( root->right ) )
        {
            int leftHeight = getHeight( root->left );
            int rightHeight = getHeight( root->right );
            
            if( abs( leftHeight-rightHeight ) > 1 )
                return false;
            else
                return true;    
        }
        else
            return false;
    }
};