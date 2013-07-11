//
//  Combination.cpp
//  
//
//  Created by 廷芳 杜 on 7/10/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector< vector<int> > pool;
    void findAllCombine( int n, int id, int k, vector<int> &com )
    {
        if( k == 0 )
        {
            pool.push_back( com );
            return;
        }
        if( id == n+1 )
            return;  
        com.push_back( id );
        findAllCombine( n, id+1, k-1, com );
        com.pop_back(); 
        findAllCombine( n, id+1, k, com );
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< int > com;
        int id = 1; 
        pool.clear(); 
        findAllCombine( n, id, k, com );
        return pool;
    }
};