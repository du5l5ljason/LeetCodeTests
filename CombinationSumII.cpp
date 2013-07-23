//
//  CombinationSumII.cpp
//  
//
//  Created by 廷芳 杜 on 7/22/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector< vector<int> > solutions;
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        solutions.clear();
        if( candidates.size()==0 ) return solutions;
        vector<int> sol;
        sort( candidates.begin(), candidates.end() );
        dfs( candidates, 0, target, sol);
        return solutions;
    }
    void dfs( vector<int> &sets, int startId, int target, vector<int> &sol )
    {
        if( target == 0 ){
            solutions.push_back( sol );
            return;
        }
        if( startId>= sets.size() || target < 0 )return;
        int numofDup = 0, i = startId;
        while( i< sets.size() && sets[i++]==sets[startId] ) numofDup++;
        for( int i= 1; i <= numofDup ; i++ )
        {
            sol.push_back( sets[startId] );
            dfs( sets, startId + numofDup , target - i*sets[startId], sol );
        }
        for( int i=1;i<=numofDup; i++ )
            sol.pop_back();
        dfs( sets, startId+numofDup, target, sol );    //do not choose this number
    }
};