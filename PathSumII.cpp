//
//  PathSumII.cpp
//  
//
//  Created by 廷芳 杜 on 4/22/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector< vector<int> > allPaths;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< int > eachPath;
        allPaths.clear();
        
        if( root == NULL ) return allPaths;
        
        findPath( root, sum, eachPath );
        
        return allPaths;
    }
    
    void findPath( TreeNode *root, int sum, vector<int> &path )
    {
        if( root == NULL ) return;
        path.push_back( root->val );
        if( root->left == NULL && root->right == NULL ) 
        {
            if( root->val == sum ) 
            {
                allPaths.push_back( path );
                path.pop_back();
                return;
            }
        }
        else
        {
            findPath( root->left, sum - root->val, path );
            findPath( root->right, sum - root->val, path );
        }
        path.pop_back();
    }
};