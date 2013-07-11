//
//  ValidParenthesis.cpp
//  
//
//  Created by 廷芳 杜 on 7/10/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> stack;
        int len = s.length();
        if( len == 0 ) return false;
        
        for( int i = 0 ; i < len ; i++ )
        {
            if( s[i] == ')' || s[i] == '}' || s[i] == ']' )
            {
                if( stack.empty() ) return false;
                if( s[i] == ')' )
                {
                    char top = stack.top();
                    stack.pop();
                    if( top != '(' ) return false;
                }
                else if( s[i] == ']')
                {
                    char top = stack.top();
                    stack.pop();
                    if( top != '[' ) return false;                    
                }
                else if( s[i] == '}')
                {
                    char top = stack.top();
                    stack.pop();
                    if( top != '{' ) return false;                    
                }
            }
            else
                stack.push( s[i] );
        }
        if( stack.empty() ) return true;
        else    return false;
    }
};