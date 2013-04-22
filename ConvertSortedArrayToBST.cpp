//
//  ConvertSortedArrayToBST.cpp
//  
//
//  Created by 廷芳 杜 on 4/22/13.
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( num.size() == 0 ) return NULL;
        
        TreeNode *newNode = NULL;
        newNode = createBSTfromArray( num, 0, num.size()-1 );
        return newNode;
    }
    
    TreeNode *createBSTfromArray( vector<int> &num, int start, int end )
    {
        if( start > end ) return NULL;
        
        int mid = (start+end)/2;
        TreeNode *newNode = new TreeNode( num[mid] );
        
        newNode->left = createBSTfromArray( num, start, mid-1 );
        newNode->right = createBSTfromArray( num, mid+1, end );
        
        return newNode;
    }
};