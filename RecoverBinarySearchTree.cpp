//
//  RecoverBinarySearchTree.cpp
//  
//
//  Created by 廷芳 杜 on 7/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
class Solution {
public:
    TreeNode *firstNode = NULL;
    TreeNode *secondNode = NULL;
    void swap( int &a, int &b )
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void inOrderTraversal( TreeNode *root, TreeNode * &pre )
    {
        if( root == NULL ) return;
        if( root->left ) inOrderTraversal( root->left, pre );
        if( pre != NULL && pre->val > root->val )
        {
            if(firstNode == NULL && secondNode == NULL )
            {
                firstNode = pre;
                secondNode = root;
            }
            else
            {
                secondNode = pre;
            }
        }
        pre = root;
        if( root->right ) inOrderTraversal( root->right, pre );
        
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( root == NULL ) return;
        if( root->left == NULL && root->right == NULL ) return;
        TreeNode *pre = NULL;
        
        inOrderTraversal( root, pre );
        if( firstNode == NULL && secondNode == NULL ) return;
        swap( firstNode->val, secondNode->val );
    }
};