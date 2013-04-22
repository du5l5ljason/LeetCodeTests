//
//  binaryTreeLevelOrderTraversal2.cpp
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
    vector<vector<int> > upBottom;
    struct node{
        TreeNode *value;
        int level;
        node( TreeNode *v, int l ){
            value = v;
            level = l;
        }
    };
    
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //BFS on the tree, and store the element with level in the upBottom.
        //Then output the upBottom in reverse order.
        if( root == NULL ) return upBottom;
        
        int level = 0;
        queue<node> u;
        upBottom.clear();
        u.push( node(root,level) );
        vector<int> vec(1, root->val );
        upBottom.push_back( vec );
        while( !u.empty() ){
            node v = u.front();
            u.pop();
            if( v.value->left ) 
            {
                if( upBottom.size()<= v.level+1 )
                {
                    vector<int> vec( 1, v.value->left->val );
                    upBottom.push_back( vec );
                }
                else
                    upBottom[v.level+1].push_back(v.value->left->val); 
                u.push( node(v.value->left, v.level + 1) );
            }
            if( v.value->right )
            {
                if( upBottom.size()<= v.level+1 )
                {
                    vector<int> vec( 1, v.value->right->val );
                    upBottom.push_back( vec );
                }
                else
                    upBottom[v.level+1].push_back(v.value->right->val); 
                u.push( node( v.value->right, v.level + 1 ) );
            }
        }
        
        vector< vector<int> > bottomUp;
        int len = upBottom.size();
        for( int i = 0 ; i< len; i++)
        {
            bottomUp.push_back( upBottom[len-i-1] );
        }
        return bottomUp;
    }
};