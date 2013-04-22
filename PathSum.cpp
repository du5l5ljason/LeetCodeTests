//
//  PathSum.cpp
//  
//
//  Created by 廷芳 杜 on 4/22/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( root == NULL ) return false;
        if( root->left == NULL && root->right == NULL )
            return root->val==sum?true:false;
        
        return hasPathSum(root->left, sum - root->val ) || hasPathSum(root->right, sum - root->val );
    }
}