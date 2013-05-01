//
//  ZigZagConversion.cpp
//  
//
//  Created by 廷芳 杜 on 4/30/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if( s.length() == 0 ) return "";
        if( nRows <= 1 ) return s;
        
        string output;
        int maxRowId = nRows-1;
        for( int j = 0 ; j<nRows; j++ )
        {
            int i=0;
            while( j + 2*i*maxRowId < s.length() )
            {
                if( j==0||j==maxRowId )
                    output = output + s[j + 2*i*maxRowId];
                else
                {
                    output = output + s[j + 2*i*maxRowId];
                    
                    if( j+2*i*maxRowId+2*(maxRowId-j) < s.length() )
                        output = output + s[j + 2*i*maxRowId + 2*(maxRowId-j)];
                }
                i++;
            }
        }
        return output;
        
    }
};