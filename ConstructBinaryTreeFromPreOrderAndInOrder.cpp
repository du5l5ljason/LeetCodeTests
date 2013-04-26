//
//  ConstructBinaryTreeFromPreOrderAndInOrder.cpp
//  
//
//  Created by 廷芳 杜 on 4/26/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( preorder.size() == 0 ) return NULL;
        if( preorder.size() != inorder.size() ) return NULL;
        
        int len = preorder.size();
        //preorder: root, leftTree, rightTree,so preorder[0] is the root value.
        TreeNode *root = buildTreeHelper( preorder, 0, len-1, inorder, 0, len-1 );
        
        return root;
    }
    
    TreeNode *buildTreeHelper( vector<int> &preorder, int startP, int endP, vector<int> &inorder, int startIn, int endIn )
    {
        if( startP > endP ) return NULL;
        if( startIn > endIn ) return NULL;
        
        int rootVal = preorder[startP];
        TreeNode *root = new TreeNode( rootVal );
        int id = findNodeInInorder( inorder, startIn, endIn, rootVal );
        
        if( id == -1 ) return NULL;
        root->left = buildTreeHelper( preorder, startP+1, (startP+1)+(id-1-startIn), inorder, startIn, id-1 );
        root->right = buildTreeHelper( preorder, (startP+1)+(id-1-startIn)+1, endP, inorder, id+1, endIn );
        
        return root;
    }
    
    int findNodeInInorder( vector<int> &inorder, int startIn, int endIn, int val )
    {
        if( startIn > endIn ) return -1; 
        
        for( int i = startIn ; i<=endIn; i++ )
        {
            if( inorder[i] == val )
                return i;
        }
        
        return -1;
    }
};