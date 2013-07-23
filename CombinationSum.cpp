//
//  CombinationSum.cpp
//  
//
//  Created by 廷芳 杜 on 7/22/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector< vector<int> > solutions;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
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
        if( startId>= sets.size() || target < 0 )return;
        if( target == 0 ){
            solutions.push_back( sol );
            return;
        }
        sol.push_back( sets[startId] );     //choose this number
        dfs( sets, startId, target - sets[startId], sol );
        sol.pop_back();
        dfs( sets, startId+1, target, sol );    //do not choose this number
    }
};