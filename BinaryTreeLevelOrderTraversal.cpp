//
//  BinaryTreeLevelOrderTraversl.cpp
//  
//
//  Created by 廷芳 杜 on 4/30/13.
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
 
//      BFS store treeNodes in a queue, add NULL between each level, whenever the top node is null, add the vec into result
//      
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        
        vector< vector<int> > pool;
        vector< int > vec;
        queue< TreeNode* > Q;
        
        //push a NULL between each level, so that we can easily partition each level
        if( root == NULL ) return pool;
        Q.push(root);
        Q.push(NULL);
        
        while( !Q.empty() )
        {
            TreeNode *v = Q.front();
            Q.pop();
            
            if( v == NULL )
            {
                pool.push_back( vec );
                vec.clear();
                if( !Q.empty() ) 
                    Q.push( NULL );     //the remaining nodes must be in the same level.
            }
            else
            {
                vec.push_back( v->val );
                if( v->left ) Q.push( v->left );
                if( v->right ) Q.push( v->right );
            }
        }
        
        return pool;
        
    }
};
