//
//  BinaryTreeZigZagTraversal.cpp
//  
//
//  Created by 廷芳 杜 on 7/6/13.
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
    struct Node{
        TreeNode *node;
        int level;
        Node( TreeNode *n, int l ){
            node = n;
            level = l;
        };
    };
    
    void addNodeToPathPool( TreeNode *node, int level, vector<vector<int>> &pathPool)
    {
        if( level > pathPool.size() )
        {
            vector<int> path;
            path.push_back( node->val );
            pathPool.push_back( path );
        }
        else
        {
            pathPool[level-1].push_back( node->val );
        }
    }
    
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > pathPool;
        
        if( root == NULL ) return pathPool;
        
        int level = 1;
        Node pt( root, level);
        
        queue<Node> u;
        u.push(pt);
        vector<int> path;
        path.push_back( pt.node->val );
        pathPool.push_back(path);
        
        while( !u.empty() )
        {
            Node v = u.front();
            u.pop();
            
            
            if( v.node->left )
            {
                u.push( Node(v.node->left, v.level+1) );
                addNodeToPathPool( v.node->left, v.level+1, pathPool );
            }
            if( v.node->right )
            {
                u.push( Node(v.node->right, v.level+1) );
                addNodeToPathPool( v.node->right, v.level+1, pathPool );                    
            }
            
            
        }
        
        for( int i = 0 ; i< pathPool.size() ; i++ )
        {
            if( i % 2 )
            {
                reverse( pathPool[i].begin(), pathPool[i].end() );
            }
        }
        
        return pathPool;
    }
};