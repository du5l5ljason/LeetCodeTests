//
//  BinaryTreeMaximumPathSum.cpp
//  
//
//  Created by 廷芳 杜 on 4/15/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int maxValue;
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( root==NULL ) return 0;
        maxValue = root->val;        
        int leftSum = maxSubPathSum( root->left );
        int rightSum = maxSubPathSum( root->right );
        
        int sum = 0;
        
        sum = ( max(max( max( maxValue, leftSum+root->val), rightSum+root->val), rightSum+leftSum+root->val) );
        
        
        return sum;
    }
    
    int maxSubPathSum( TreeNode *root )
    {
        if( root == NULL ) return 0;
        
        int left = maxSubPathSum( root->left );
        int right = maxSubPathSum( root->right );
        int maxSingle = max( max(left+root->val, right+root->val ), root->val );
        
        maxValue = max( maxValue, max( maxSingle, root->val+left+right ) );
        return maxSingle;
    }
};