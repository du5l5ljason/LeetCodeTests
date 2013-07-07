//
//  2Sum.cpp
//  
//
//  Created by 廷芳 杜 on 4/10/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
// Two ways
// 1. Sort the array, and put start and end pointers and find the correct two numbers in the array by moving the pointers.
// The problem is how to save the indices because after sorting, since the original indices have been changed.
// One approach is to save them into an unordered_map, hash map, so that we can search for the index given one particular number
// But how to handle the problem that if the two numbers are equal? We could check the id.
// TComplexity O(nlogn) SC O(n)
// 2. Create a map. Each number is paired to a number that adds up to target. The next step is to check if there is one number
// in the array that is the same as that number.
// TC O(n^2) /O(nlogn) SC O(n)
// Corner Case: The pair contains two same numbers.
// The output should be in ascending order

#include <iostream>

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        map<int, int> map;
        
        int len = numbers.size();
        int l1 = 0;
        int l2 = 0;
        if( len < 2 ) return result;

        //Create map, the value of the ith element in the map is the value that meets ( target - numbers[i] )  
        for( int i  = 0 ; i< numbers.size(); i++ )
        {
            map[i] = target - numbers[i];
        }
        
        //Search map[i] 
        for( int i = 0 ; i<numbers.size() ; i++ )
        {
            for( int j = 0 ; j < numbers.size(); j++ )
            {
                if( map[i] == numbers[j] && i!= j ) //if two numbers are the same.
                {
                    l1 = j;
                    l2 = i;
                }
            }
        }
        
        if( l1 > l2 )
            swap( l1 , l2 );    //Reorder if needed.
        
        result.push_back( l1+1 );
        result.push_back( l2+1 );
        return result;
        
        
    }
};
