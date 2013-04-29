//
//  PermutationsI.cpp
//  
//
//  Created by 廷芳 杜 on 4/29/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >result;
        if( num.size() == 0 ) return result;
        
        
        permuteHelper( num, result, 0, num.size()-1 );
        
        return result;
    }
    
    void permuteHelper( vector<int> &num, vector< vector<int> > &result, int startId, int endId )
    {
        if( startId == endId ) // goes to the end
        {
            //check if this num is already in the result
            //if it is 
            if( !isFound( result, num ) )
                result.push_back( num );
        }
        
        for( int j = startId; j <= endId; j++ )
        {
            swap( num[startId], num[j] );
            permuteHelper( num, result, startId+1, endId);
            swap( num[startId], num[j] );
        }
    }
    
    bool isFound( vector<vector<int>> &pool, vector<int> sample )
    {
        for( int i = 0 ; i< pool.size() ; i++ )
        {
            if( sample == pool[i] )
                return true;
        }
        
        return false;
    }
};