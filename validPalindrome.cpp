//
//  validPalindrome.cpp
//  testValidPalindrome
//
//  Created by 廷芳 杜 on 4/18/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool isAlphaNum( const char *c )
    {
        if( (*c)>='a' && (*c)<='z' ) return true;
        if( (*c)>='A' && (*c)<='Z' ) return true;
        if( (*c)>='0' && (*c)<='9' ) return true;
        
        return false;
    }
    
    char *toLower( const char *c )
    {
        char *lc = new char();
        *lc = *c+32;
        return lc;
    }
    
    bool isUpper( const char *c )
    {
        if( (*c)>='A' && (*c)<='Z' ) return true;
        return false;
    }
    string deleteTokens(string s)
    {
        string str="";
        
        for( int i = 0 ; i< s.length(); i++ )
        {
            const char *c = s.substr(i,1).c_str();
            if( isAlphaNum( c ) )   
            {
                if( isUpper(c) )
                {
                    char *lc = toLower(c);
                    string st(lc);
                    str += st;
                }
                else
                    str += s[i];           
            }
            
        }
        
        return str;
    }
    
    string reverse( string input )
    {
        int len = input.size();
        if( len == 0 ) return input;
        string output="";
        for( int i = len-1 ; i>=0 ; i-- )
        {
            output += input[i] ;
        }
        return output;
    }
    
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( s.length() == 0 ) return true;
        
        string newString = deleteTokens(s);
        if( newString.length() == 0 ) return true;
        
        string reverseString = reverse(newString );
        
        if( newString == reverseString )
            return true;
        else
            return false;
        
    }
};
