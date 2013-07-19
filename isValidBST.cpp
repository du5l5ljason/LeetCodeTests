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
        TreeNode *pre = NULL;
        return checkBST( root, pre );
    }
    bool checkBST( TreeNode *root, TreeNode *&pre )
    {
        if( root == NULL ) return true;
        bool isLeft = checkBST( root->left, pre );
        if( pre!=NULL && pre->val >= root->val ) return false;
        pre = root;
        bool isRight = checkBST( root->right, pre );
        return isLeft && isRight;
    }
};