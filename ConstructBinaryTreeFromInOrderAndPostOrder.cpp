//
//  ConstructBinaryTreeFromInOrderAndPostOrder.cpp
//  
//
//  Created by 廷芳 杜 on 4/26/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( inorder.size() == 0 ) return NULL;
        if( inorder.size() != postorder.size() ) return NULL;
        
        TreeNode *root = NULL;
        
        int len = inorder.size();
        root = buildTreeHelper( inorder, 0, len-1, postorder, 0, len-1 );
        
        return root;
    }
    
    TreeNode* buildTreeHelper( vector<int> &inorder, int startIn, int endIn, vector<int> &postorder, int startP, int endP )
    {
        if( inorder.size() == 0 ) return NULL;
        if( inorder.size() != postorder.size() ) return NULL;
        if( startIn > endIn ) return NULL;
        if( startP > endP ) return NULL;
        
        int nodeVal = postorder[endP];
        TreeNode *node = new TreeNode(nodeVal);
        int id = findNodeinInorder( inorder, startIn, endIn, nodeVal);
        
        if( id == -1 ) return NULL;
        node->left = buildTreeHelper( inorder, startIn, id-1, postorder, startP, startP+id-startIn-1 );
        node->right = buildTreeHelper( inorder, id+1, endIn, postorder, startP+id-startIn, endP-1 );
        
        return node;
    }
    
    int findNodeinInorder( vector<int> &inorder, int startIn, int endIn, int val )
    {
        if( startIn > endIn ) return -1;
        
        for( int i = startIn; i<=endIn; i++ )
        {
            if( inorder[i] == val )
                return i;
        }
        
        return -1;
    }
};