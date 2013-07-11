//
//  SubSetsII.cpp
//  
//
//  Created by 廷芳 杜 on 7/10/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector< vector<int> > pool;
    void findAllSubsets( vector<int> &S, vector<int> &subset, int id )
    {
        if( id == S.size() )
        {
            pool.push_back( subset );
            return;
        }
        
        //create a vector to store duplicate
        vector< int > dup;
        for( int i = id; i < S.size(); i++ )
        {
            if( S[i] == S[id])
            {
                dup.push_back( S[i] );
            }
            else 
                break;
        }
        
        for( int i = 1; i <= dup.size(); i++ )
        {
            for( int j = 0; j < i; j++ )
                subset.push_back( dup[0] );
            
            findAllSubsets( S, subset, id+dup.size() );
            for( int k = 0 ; k < i ; k++ )
                subset.pop_back();
        }
        
        
        findAllSubsets( S, subset, id+dup.size() );
        
        return;
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        pool.clear();
        if( S.size()==0 ) return pool;
        
        int id = 0;
        vector<int> subset;
        
        sort( S.begin(), S.end() );
        findAllSubsets( S, subset, id );
        
        return pool;
    }
};