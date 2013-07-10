//
//  3Sum.cpp
//  
//  Tag: sort
//  Created by 廷芳 杜 on 4/30/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
//  The Key problem of this question is how to avoid duplication. Other than that, it is just a twoSum question.
//  The most intuitive idea is to create a map. We can save them by a pair, because the third element is fixed if two of 
//  them are given. Thus, a unique triplet should have a unique pair. We can use this pair as key.
//  Another idea is to check if the next number is the same of current number, if yes, skip to the next one, this is a much 
//  light weighted way.

#include <iostream>

class Solution {
public:
    
    int hashFunc(int num1, int num2)
    {
        // A simple hash function to return a unique key given a unique pair of integer.
        int temp = num1*101 + num2;
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
                    //store a potential triplet.
                    vector<int> vec;
                    vec.push_back(num[i]);
                    vec.push_back(num[start]);
                    vec.push_back(num[end]);
                    
                    //Check if already found.
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
                
                //check for right pair.
                else if( num[start] + num[end] + num[i] > 0 )   
                    end--;
                else
                    start++;
            }
            
            i++;
        }
    }
};
