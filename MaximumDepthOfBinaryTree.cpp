//
//  MaximumDepthOfBinaryTree.cpp
//  
//
//  Created by 廷芳 杜 on 4/1/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( root == NULL ) return 0;
        if( root->left == NULL && root->right == NULL ) return 1;
        else
            return 1 + max( maxDepth( root->left ), maxDepth( root->right ) );
    }
};