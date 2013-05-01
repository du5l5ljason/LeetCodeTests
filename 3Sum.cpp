//
//  3Sum.cpp
//  
//
//  Created by 廷芳 杜 on 4/30/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    
    int hashFunc(int num1, int num2)
    {
        int temp = num1*101 + num2;
        //if( temp < 0 )
        //  return -1;
        //else
        return temp;
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        if( num.size() < 3 ) return result;
        
        int len = num.size();
        unordered_map<int, int> isFound;
        
        sort( num.begin(), num.end() );
        int i=0;
        while( i<len-1 )
        {
            int start = i+1;
            int end = len-1;
            while( end>start )
            {
                if( num[start] + num[end] + num[i] == 0 )
                {
                    vector<int> vec;
                    vec.push_back(num[i]);
                    vec.push_back(num[start]);
                    vec.push_back(num[end]);
                    int hashNumber = hashFunc(num[start], num[end]);
                    if(isFound.find(hashNumber)!=isFound.end()) //found 
                    {
                        start++;
                        end--;
                    }
                    else  //not found
                    {
                        isFound[hashNumber] = 0;
                        result.push_back(vec);
                        start++;
                        end--;
                    }    
                    
                }
                
                else if( num[start] + num[end] + num[i] > 0 )   
                    end--;
                else
                    start++;
            }
            
            i++;
        }
    }
};