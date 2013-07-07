//
//  SurroundedRegions.cpp
//  
//
//  Created by 廷芳 杜 on 7/5/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
class Solution {
public:
    void dfs( int i, int j, vector<vector<char>> &board ){
        if( i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j]!='O')
            return;
        
        board[i][j] = 'D';
        dfs( i-1, j, board );
        dfs( i+1, j, board );
        dfs( i, j+1, board );
        dfs( i, j-1, board );
        
    }
    
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( board.size() == 0 ) return;
        if( board[0].size() == 0 ) return;
        
        for( int i =0; i < board.size(); i++ )
        {
            dfs( i, 0, board );
            dfs( i, board[i].size()-1, board);
        }
        
        for( int j = 0 ; j < board[0].size(); j++ )
        {
            dfs( 0, j, board );
            dfs( board.size()-1, j, board );
        }
        
        for( int i = 0 ; i<board.size(); i++ )
        {
            for( int j = 0 ; j < board[i].size(); j++ )
            {
                if( board[i][j] == 'D' ) board[i][j] = 'O';
                else if( board[i][j] == 'O' ) board[i][j] = 'X';
            }
        }
        return;
    }
};