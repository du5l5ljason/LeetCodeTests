//
//  SurroundedRegions.cpp
//  
//
//  Created by 廷芳 杜 on 4/18/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isValid( vector< vector<char> > &board, int i, int j, vector< vector<bool> > isMarked) 
    {
        // i is id of row, j is id of col, if they are at the bound, it is not valid.
        // 1. at the bound
        // 2. already marked
        // 3. is 'X'
        if( j <0 || j >= board[0].size() ) return false;
        if( i <0 || i >= board.size() ) return false;
        if( isMarked[i][j] == true ) return false;
        if( board[i][j] == 'X' ) return false;
        
        return true; //is 'O', and unvisited, not at bound
    }
    
    bool capture( vector< vector<char> > &board, int i, int j, vector< vector<bool> > &isMarked)
    {    
        //if this valid point is at the bound, this region is a region surrounded by 'X'
        if( i == 0 || i == board.size()-1 || j == 0 || j == board[0].size()-1 ) return false;
        
        isMarked[i][j] = true;
        board[i][j] = 'X';
        if( isValid(board, i-1, j, isMarked ) )
        {
            if(!capture( board, i-1, j, isMarked ) )//if it is not a region.
            {
                board[i][j] = 'O';
                return false;
            }    
        }
        if( isValid(board, i, j-1, isMarked)  )
        {
            if(!capture( board, i, j-1, isMarked ) )//if it is not a region.
            {
                board[i][j] = 'O';
                return false;
            }    
        }
        if( isValid(board, i+1, j, isMarked)  )
        {
            if(!capture( board, i+1, j, isMarked ) )//if it is not a region.
            {
                board[i][j] = 'O';
                return false;
            }    
        }
        if( isValid(board, i, j+1, isMarked)  )
        {
            if(!capture( board, i, j+1, isMarked ) )//if it is not a region.
            {
                board[i][j] = 'O';
                return false;
            }    
        }
        
        return true;
    }
    
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = board.size();
        if( row == 0 ) return;
        int col = board[0].size();
        if( col == 0 ) return;
        vector< vector<bool> > isMark(row, vector<bool>(col,false));
        
        for( int i = 0 ; i<row; i++ )
        {
            for( int j = 0; j<col; j++ )
            {
                if( isValid(board, i, j, isMark ) )
                    capture( board, i, j, isMark );
            }
        }
    }
};