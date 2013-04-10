//
//  LongestPalindrome.cpp
//  testLinkedList_InterviewQuestions
//
//  Created by 廷芳 杜 on 4/10/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string lp;
        if( s.length() == 1 ) 
        {
            lp = s;
            return lp;
        }
        
        int lenOfLp = 0;
        bool isOdd = 0;
        int id = 0;
        for( int i = 0; i < s.length() ; i++ )
        {
            int oddLen = expandOdd( s, i );
            int evenLen = expandEven( s, i );
            lenOfLp = max( max(oddLen, evenLen), lenOfLp  );
            if( oddLen == lenOfLp )
            {
                isOdd = 1;
                id = i;
            }    
            else if( evenLen == lenOfLp )
            {
                isOdd = 0;
                id = i;
            }     
        }
        
        if ( isOdd )
            lp = getOddLp( s, id , lenOfLp );
        else
            lp = getEvenLp( s, id, lenOfLp );
        
        return lp;
        
    }
    
    int expandOdd( string s, int id )
    {
        int len = s.length();
        int range = min( len-id, id+1 );
        int counter = 0;
        
        for ( int j = 0; j< range; j++ )
        {
            if( s[id-j] == s[id+j] )
                counter++;
            else
                break;
        }
        
        return 2*counter-1;
    }
    
    int expandEven( string s, int id )
    {
        int len = s.length();
        int range = min( len-id-1, id+1 );
        int counter = 0;
        
        for( int j = 0 ; j < range ; j++ )
        {
            if( s[id-j] == s[id+1+j] )
                counter++;
            else
                break;
        }
        
        return 2*counter;
    }
    
    string getOddLp( string s, int id, int len )
    {
        int offset = len/2;
        return s.substr( id-offset, len );
    }
    
    string getEvenLp( string s, int id, int len )
    {
        int offset = len/2;
        return s.substr( id-offset+1, len );
    }
};