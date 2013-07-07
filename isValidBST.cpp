//
//  isValidBST.cpp
//  
//
//  Created by 廷芳 杜 on 7/6/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( root == NULL ) return true;
        int min = -100000;
        int max = 100000;
        
        return isValidBSTHelper( root, min, max );
    }
    bool isValidBSTHelper( TreeNode *root, int min, int max )
    {
        if( root == NULL ) return true;
        
        return (root->val>min&&root->val<max)
        &&isValidBSTHelper( root->left, min, root->val )
        &&isValidBSTHelper( root->right, root->val, max );
    }
};