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
class Solution {
public:
    struct BFSNode{
        TreeNode *node;
        int level;
        BFSNode(TreeNode *n, int l):level(l){
            node = n;
        };
    };
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > levelPool;
        if( root == NULL ) return levelPool;
        
        queue<BFSNode> u;
        int level = 0;
        u.push( BFSNode( root, level ) );
        vector<int> vec;
        vec.push_back( root->val );
        levelPool.push_back(vec);
        while( !u.empty() ){
            BFSNode v = u.front();
            u.pop();
            
            if( v.node->left != NULL )
            {
                if( levelPool.size()<= v.level+1 )
                {
                    vector<int> vec;
                    vec.push_back( v.node->left->val );
                    levelPool.push_back( vec );
                }   
                else
                    levelPool[v.level+1].push_back( v.node->left->val );
                u.push( BFSNode( v.node->left, v.level+1 ));
                
            }    
            if( v.node->right != NULL )
            {
                if( levelPool.size()<= v.level+1 )
                {
                    vector<int> vec;
                    vec.push_back( v.node->right->val );
                    levelPool.push_back( vec );
                }   
                else
                    levelPool[v.level+1].push_back( v.node->right->val );   
                u.push( BFSNode( v.node->right, v.level+1 ));
            }    
        }
        
        return levelPool;
    }
};