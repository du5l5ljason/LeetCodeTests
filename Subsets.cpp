//
//  Subsets.cpp
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
        
        //add this number
        subset.push_back( S[id] );
        findAllSubsets( S, subset, id+1 );
        subset.pop_back();
        
        //do not add this number
        findAllSubsets( S, subset, id+1 );
        
        return;
    }
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        pool.clear();
        if( S.size() == 0 ) return pool;
        
        //subset must be in non-descent order.
        sort( S.begin(), S.end() );
        int id = 0;
        vector< int > subset;
        
        findAllSubsets( S, subset, id );
        
        return pool;
    }
};