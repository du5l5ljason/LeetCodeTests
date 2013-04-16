//
//  MinimumDepthOfBinaryTree.cpp
//  
//
//  Created by 廷芳 杜 on 4/1/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
class Solution {
public:
    
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        
        if( root->left == NULL) 
            return 1 + minDepth( root->right );
        if( root->right == NULL ) 
            return 1 + minDepth( root->left );
            
        return 1+ min( minDepth( root->left ), minDepth( root->right ) );       
    }
};
