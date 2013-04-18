//
//  SumRootToLeafNumbers.cpp
//  
//
//  Created by 廷芳 杜 on 4/18/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector< vector<int> > allNumbers;
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( root == NULL ) return 0;
        
        vector< int > vec;
        vector< int > sum;
        allNumbers.clear();
        vec.clear();
        findAllNumbers( root, vec );
        
        int result = getSum( sum );
        return result;
    }
    
    void findAllNumbers( TreeNode *root, vector<int> &vec )
    {
        if(root == NULL) return;
        vec.push_back(root->val);
        if( root->left == NULL && root->right == NULL ) 
        {
            //this is the leaf node, add vec into the allNumbers
            
            allNumbers.push_back( vec );
        }
        
        else
        {
            findAllNumbers( root->left, vec );
            findAllNumbers( root->right, vec );
            
        }
        vec.pop_back();
    }
    
    int getSum(vector <int> &sum)
    {
        //transfer allNumbers to the sum.
        int result = 0;
        int temp = 0;
        for( int i = 0 ; i< allNumbers.size(); i++ )
        {
            for( int j=0; j<allNumbers[i].size(); j++ )
            {   
                temp = (temp*10+allNumbers[i][j])>=2147483647?2147483647:(temp*10+allNumbers[i][j]);
            }
            sum.push_back( temp );
            temp = 0;
        }
        
        for( int i = 0 ; i<sum.size(); i++ )
        {
            result = (result + sum[i])>=2147483647?2147483647:(result + sum[i]);
        }
        
        return result;
    }
};