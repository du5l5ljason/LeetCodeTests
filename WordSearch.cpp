//
//  WordSearch.cpp
//  
//
//  Created by 廷芳 杜 on 4/30/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = board.size();
        if( row == 0 ) return false;
        int col = board[0].size();
        if( col == 0 ) return false; 
        if( word.length() == 0 ) return false;
        
        vector<vector<bool>> isFound(row,vector<bool>(col,false) );
        
        for( int i = 0 ; i < row; i++ )
        {
            for( int j = 0; j < col ; j++ )
            {
                if( board[i][j] == word[0] )
                {
                    if( isSolved(board, isFound, i, j, word, 0) )
                        return true;
                    else
                    {
                        for(int k = 0 ; k < row; k++ )
                        {
                            for( int m = 0 ; m < col ; m++ )
                            {
                                isFound[k][m] = false;
                            }
                        }
                    }
                }
            }
        }
        
        return false;
    }
    
    bool isValid( vector<vector<char> > &board, vector<vector<bool> > &isFound, int x, int y, string word, int id )
    {
        if( x>=0 && x<board.size() && y>=0 && y<board[0].size() )
        {
            if( !isFound[x][y] && board[x][y] == word[id])
                return true;
            else
                return false;
        }
        return false;
    }
    
    bool isSolved( vector<vector<char> > &board, vector<vector<bool> > &isFound, int x, int y, string word, int id )
    {
        if( id == word.length()-1 ) return true;
        
        isFound[x][y] = true;
        bool isLeft=false;
        bool isRight=false;
        bool isUp=false;
        bool isDown=false;
        if( isValid( board, isFound,x-1, y, word, id+1 ) )
            isLeft = isSolved( board, isFound, x-1, y, word, id+1 );
        if( isValid( board, isFound,x+1, y, word, id+1 ) )
            isRight = isSolved( board, isFound,x+1, y,word, id+1 );
        if( isValid( board, isFound, x, y-1, word, id+1 ) )
            isDown = isSolved( board, isFound, x, y-1,word,id+1 );
        if( isValid( board, isFound, x, y+1, word, id+1 ) )
            isUp = isSolved( board, isFound, x, y+1,word,id+1 );
        
        return isLeft||isRight||isDown||isUp;
    }
};