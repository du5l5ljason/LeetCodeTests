//
//  SymmetricTree.cpp
//  
//
//  Created by 廷芳 杜 on 5/1/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( root == NULL ) return true;
        if( root->left == NULL && root->right == NULL ) return true;
        
        return checkSym( root->left, root->right );
    }
    
    bool checkSym( TreeNode *lc, TreeNode *rc)
    {
        if( lc == NULL && rc == NULL ) return true;
        if( lc != NULL && rc == NULL ) return false;
        if( lc == NULL && rc != NULL ) return false;
        
        //lc!=NULL, rc!=NULL
        return (lc->val==rc->val) && checkSym( lc->left, rc->right ) && checkSym( lc->right, rc->left) ;
    }
};