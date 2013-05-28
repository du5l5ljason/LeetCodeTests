//
//  NQueens.cpp
//  testMthElement
//
//  Created by 廷芳 杜 on 5/9/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<vector<string> > solution;
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        solution.clear();
        
        if( n<=0 ) return solution;
        if( n==1 ) 
        {
            vector<string> s;
            s.push_back( "Q" );
            solution.push_back(s);
            return solution;
        }
        
        string str;
        for( int i = 0 ; i<n ; i++ )
        {
            str += ( '1'+i );
        }
        
        solveQueens( str, 0, n-1 );
        
        return solution;
    }
    
    void solveQueens( string str, int curId, int endId )
    {
        if( curId == endId )
        {
            if( isValid( str ) )
            {
                addToSolution( str );
            }
            return;
        }
        
        for( int j = curId; j <=endId ; j++ )
        {
            swap( str[curId], str[j] );
            solveQueens( str, curId+1, endId );
            swap( str[curId], str[j] );
        }
        
        return;
    }
    
    bool isValid( string str )
    {
        
        int len = str.length();
        bool isColValid[len][len];
        for( int i=0; i<len; i++ )
            for( int j=0; j<len; j++ )
                isColValid[i][j] = true;
        
        for( int i = 0 ; i< len; i++ )
        {
            int id = (int)(str[i]-'1');     //col id.
            if( isColValid[i][id] == false )
                return false;
            
            for( int j=0; j < len ; j++ )
                isColValid[j][id] = false;
            for( int j=0; j < len ; j++ )
                isColValid[i][j] = false;
            
            for( int j=0; j <len; j++ )
            {
                for( int k = 0 ; k <len; k++ )
                {
                    if( (j-k)==(i-id) || (j+k)==(i+id) )
                        isColValid[j][k] = false;
                }
            }
        }
        
        return true;
    }
    
    void addToSolution( string str )
    {
        vector<string> sol;
        
        for( int i = 0 ; i< str.length() ; i++ )
        {
            int id = (int)(str[i]-'1');
            string s;
            for( int j=0; j<str.length();j++ )
            {
                if( j != id )
                    s += ".";
                else
                    s += "Q";
            }
            
            sol.push_back(s);
        }
        
        solution.push_back( sol );
    }
};